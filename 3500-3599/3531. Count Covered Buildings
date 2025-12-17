class Solution {
    public int countCoveredBuildings(int n, int[][] buildings) {
        Map<Integer, List<Integer>> buildingsAtX = new HashMap<>();
        Map<Integer, List<Integer>> buildingsAtY = new HashMap<>();

        for (int[] building : buildings) {
            int xCoord = building[0];
            int yCoord = building[1];
          
            buildingsAtX.computeIfAbsent(xCoord, k -> new ArrayList<>()).add(yCoord);
            buildingsAtY.computeIfAbsent(yCoord, k -> new ArrayList<>()).add(xCoord);
        }

        for (Map.Entry<Integer, List<Integer>> entry : buildingsAtX.entrySet()) {
            Collections.sort(entry.getValue());
        }
      
        for (Map.Entry<Integer, List<Integer>> entry : buildingsAtY.entrySet()) {
            Collections.sort(entry.getValue());
        }

        int coveredBuildingCount = 0;

        for (int[] building : buildings) {
            int xCoord = building[0];
            int yCoord = building[1];
          
            List<Integer> buildingsOnSameX = buildingsAtX.get(xCoord);
            List<Integer> buildingsOnSameY = buildingsAtY.get(yCoord);

            boolean hasLeftBuilding = buildingsOnSameY.get(0) < xCoord;
            boolean hasRightBuilding = xCoord < buildingsOnSameY.get(buildingsOnSameY.size() - 1);
            boolean hasBelowBuilding = buildingsOnSameX.get(0) < yCoord;
            boolean hasAboveBuilding = yCoord < buildingsOnSameX.get(buildingsOnSameX.size() - 1);
          
            if (hasLeftBuilding && hasRightBuilding && hasBelowBuilding && hasAboveBuilding) {
                coveredBuildingCount++;
            }
        }

        return coveredBuildingCount;
    }
}
