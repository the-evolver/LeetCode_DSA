class Solution {
    
   public  int maxPoints(int[][] points) {

        int pLen = points.length;
        if (pLen < 3) {
            return pLen;
        }

        HashMap<Double, Integer> hm;

        int maxNoOfPoints = Integer.MIN_VALUE;

        for (int i = 0; i < pLen; i++) {

            hm = new HashMap<>();
            
            for (int j = i + 1; j < pLen; j++) {
                
                double slope = getSlope(points[i], points[j]);
                
                hm.put(slope,hm.getOrDefault(slope,0)+1);

            }

            for (Map.Entry<Double, Integer> entry : hm.entrySet()) {
                maxNoOfPoints = Math.max(maxNoOfPoints, entry.getValue());

            }
                    
        }

        return maxNoOfPoints+1;

    }


     public static double getSlope(int[] cord1, int[] cord2) {

        double mY = cord2[1] - cord1[1];
        double mX = cord2[0] - cord1[0];
        if (mY == 0) return 0; // edge case
        if (mX == 0) return Double.POSITIVE_INFINITY; // edge case
        return mY/mX;
    }
}