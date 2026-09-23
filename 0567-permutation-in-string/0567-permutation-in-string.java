class Solution {
    public boolean checkInclusion(String s1, String s2) {
        int n1 = s1.length();
        int n2 = s2.length();

        if (n1 > n2) {
            return false;
        }

        int[] count1 = new int[26];
        int[] count2 = new int[26];

        for (int i = 0; i < n1; i++) {
            count1[s1.charAt(i) - 'a']++;
            count2[s2.charAt(i) - 'a']++;
        }

        int matches = 0;
        for (int i = 0; i < 26; i++) {
            if (count1[i] == count2[i]) {
                matches++;
            }
        }

        for (int i = 0; i < n2 - n1; i++) {
            if (matches == 26) {
                return true;
            }

            int r = s2.charAt(i + n1) - 'a';
            count2[r]++;
            if (count2[r] == count1[r]) {
                matches++;
            } else if (count2[r] == count1[r] + 1) {
                matches--;
            }

            int l = s2.charAt(i) - 'a';
            count2[l]--;
            if (count2[l] == count1[l]) {
                matches++;
            } else if (count2[l] == count1[l] - 1) {
                matches--;
            }
        }

        return matches==26;
    }
}