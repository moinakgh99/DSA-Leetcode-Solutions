class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();

        sort(skill.begin(), skill.end());

        int i = 0, j = n - 1;
        int sum = skill[i] + skill[j];

        long long chemistry = 0;

        while( i < j ) {
            int currSkill = skill[i] + skill[j];
            if(currSkill != sum) return -1;

            chemistry += (long long)skill[i] * (long long)skill[j];
            i++;
            j--;
        }


        return chemistry;
    }
};