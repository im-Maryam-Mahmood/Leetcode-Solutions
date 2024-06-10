class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        for(int i = 0; i < students.size(); ++i){
            if(students[i] == sandwiches[0]){
                students.erase(students.begin() + i);
                sandwiches.erase(sandwiches.begin());
                return countStudents(students, sandwiches);
            }
        }
        return students.size();
    }
};