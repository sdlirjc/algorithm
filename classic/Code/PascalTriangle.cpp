class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> >v;
        if (numRows==0)return v;
        if(numRows==1){vector<int>l;l.push_back(1);v.push_back(l);return v;}
        if(numRows==2){vector<int>l;l.push_back(1);v.push_back(l);vector<int>l2;l2.push_back(1);l2.push_back(1);v.push_back(l2);return v;}
        vector<int>nv;
        nv.push_back(1);
        v=generate(numRows-1);
        vector<int> ll=v[v.size()-1];
        for(int i=0;i<numRows-2;i++){ nv.push_back(ll[i]+ll[i+1]); }
        nv.push_back(1);
        v.push_back(nv);
        return v;
    }
};
