class Solution {
    public String convertToTitle(int columnNumber) {
        StringBuilder result = new StringBuilder();
      
        while (columnNumber != 0) {
            columnNumber--;
          
            char currentChar = (char) ('A' + columnNumber % 26);
            result.append(currentChar);
          
            columnNumber /= 26;
        }
      
        return result.reverse().toString();
    }
}
