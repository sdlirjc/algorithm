class Solution {

public:

    void generateSet(vector<int>&S,int step, vector<vector<int> >&set, vector<int>&s){

        

            for(int j=step;j<S.size();j++){

                s.push_back(S[j]);

                set.push_back(s);

                if(j<S.size()-1)generateSet(S,j+1,set,s);

                s.pop_back();

            }

    }

    vector<vector<int> > subsets(vector<int> &S) {

        vector<vector<int> >set;

        

        if(S.size()==0)return set;

        vector<int>t;

        set.push_back(t);

        sort(S.begin(),S.end());

        generateSet(S,0,set,t);

        return set;

    }

};
