import pandas as pd

def capitalize_content(user_content: pd.DataFrame) -> pd.DataFrame:
    
    def convert_word(word: str) -> str:
        if "-" in word:
            parts = word.split("-")
            
            #  Apply hyphen rule ONLY if all parts are valid words
            if all(part.isalpha() for part in parts):
                return "-".join(
                    part[0].upper() + part[1:].lower()
                    for part in parts
                )
            
            #  Otherwise treat as normal word
            return word.lower().capitalize() if word and word[0].isalpha() else word.lower()
        
        # Normal word
        return word.lower().capitalize() if word and word[0].isalpha() else word.lower()

    def convert_text(text: str) -> str:
        return " ".join(convert_word(word) for word in text.split(" "))

    user_content["converted_text"] = user_content["content_text"].apply(convert_text)

    return user_content.rename(columns={"content_text": "original_text"})[
        ["content_id", "original_text", "converted_text"]
    ]
