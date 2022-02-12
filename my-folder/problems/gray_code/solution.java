class Solution {
    public int binToDecimal(String bin) {
        int n = bin.length();
        int res = 0;
        int p = 1;
        int idx = n - 1;
        while (idx >= 0) {
            res += (bin.charAt(idx) - '0') * p;
            idx--;
            p *= 2;
        }

        return res;
    }
    
    public List<String> help(int n) {
        if (n == 1) {
            List<String> x = new ArrayList<String>();
            x.add("0");
            x.add("1");
            return x;
        }
        
        List<String> recursionResult = help(n - 1);
        List<String> myResult = new ArrayList<String>();
        
        int sz = recursionResult.size();
        
        for (int i = 0; i < sz; i++)
            myResult.add("0" + recursionResult.get(i));
        for (int i = sz - 1; i >= 0; i--)
            myResult.add("1" + recursionResult.get(i));
        
        return myResult;
    }
    
    public List<Integer> grayCode(int n) {
        List<Integer> result = new ArrayList<Integer>();
        List<String> temp = help(n);
        for(String s : temp) {
            result.add(binToDecimal(s));
        }
        return result;
    }
}