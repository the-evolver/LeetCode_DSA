class Solution {
    public boolean repeatedSubstringPattern(String s) {
        String str = s + s;
        if (str.substring(1, str.length() - 1).contains(s))
            return true;
        return false;
    }
}