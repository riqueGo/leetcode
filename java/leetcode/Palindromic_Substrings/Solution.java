package leetcode.Palindromic_Substrings;

public class Solution {

    public static void main(String[] args) {
        Solution solution = new Solution();
        int result = solution.countSubstrings("abbcbd");
        System.out.println(result);
    }

    public int countSubstrings(String s) {
        int count = 0;
        for (int i = 0; i < s.length(); i++) {
            count += countPalindromes(s, i, i);
            count += countPalindromes(s, i, i+1);
        }

        return count;
    }

    private int countPalindromes(String s, int left, int right) {
        int count = 0;

        while (left >= 0 && right < s.length() && s.charAt(left) == s.charAt(right)) {
            count++;
            left--;
            right++;
        }

        return count;
    }

    public int bruteForceCountSubstrings(String s) {
        int count = 0;
        for (int end = 1; end < s.length(); end++) {
            for (int start = 0; start < s.length(); start++) {
                if (start + end <= s.length() && checkPalindromes(s.substring(start, start+end))) {
                    count++;
                }
            }
        }
        if (checkPalindromes(s)) count++;
        return count;
    }

    private boolean checkPalindromes(String s) {
        if (s.length()<2) {
            return true;
        }
        int left = 0, right = s.length()-1;
        boolean result = true;
        while (left < right) {
            if(s.charAt(left) != s.charAt(right)) {
                result = false;
                break;
            }
            left++;
            right--;
        }
        return result;
    }
}
