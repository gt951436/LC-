class Solution {
    public String kthDistinct(String[] arr, int k) {
        HashMap<String, Integer> sf = new HashMap<>();
        for (String str : arr) {
            if (sf.containsKey(str)) {
                sf.put(str, sf.get(str) + 1);
            } else {
                sf.put(str, 1);
            }
        }
        int i = 0;
        for (String s : arr) {
            if (sf.get(s) == 1) {
                ++i;
            }
            if (i == k) {
                return s;
            }
        }
        return "";
    }
}