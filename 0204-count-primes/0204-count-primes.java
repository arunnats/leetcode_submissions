class Solution {
    public int countPrimes(int n) {
        if (n <= 2) return 0; 
        
        int count = 0;
        ArrayList<Boolean> prime = new ArrayList<>(Collections.nCopies(n, true));

        prime.set(0, false);
        prime.set(1, false);

        for (int i = 2; i < n; i++) {
            if (prime.get(i)) {
                count++;
                for (int j = i * 2; j < n; j += i) { 
                    prime.set(j, false);
                }
            }
        }
        return count;
    }
}
