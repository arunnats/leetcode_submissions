class Solution {
    public int minSteps(int n) {
        ArrayList<Integer> dp = new ArrayList<>(n + 1);
        
        for (int i = 0; i <= n; i++) {
            dp.add(Integer.MAX_VALUE);
        }
        
        dp.set(1, 0);

        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                if (i % j == 0) {
                    dp.set(i, Math.min(dp.get(i), dp.get(j) + i / j));
                }
            }
        }

        return dp.get(n);
    }
}