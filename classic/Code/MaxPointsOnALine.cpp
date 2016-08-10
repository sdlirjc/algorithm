//bad

/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        map<float,int>m;
        int ma=0;
        for(int i=0;i<points.size();i++){
            m.clear();
            //m[float(INT_MIN)] = 0;
            int d=1;
            for(int j=0;j<points.size();j++){
                if(i==j){continue;}
                Point p1=points[i];
                Point p2=points[j];
                if(p1.x==p2.x&&p1.y==p2.y) {
                    d++;
                    continue;
                }
                float s=gs(p1,p2);
                m[s]++;
            }
            for (map<float, int>::iterator it = m.begin(); it != m.end(); ++it){
                ma=max(it->second+d,ma);
            }
        }
        return ma;
    }
    float gs(Point p1,Point p2){
        if (p1.x-p2.x==0) {
            return float(INT_MAX);
        }
        else{return (float)((p1.y-p2.y)/(p1.x-p2.x));}
    }
};


//good


/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
    int maxPoints(vector<Point> &points) {
        unordered_map<float,int>statistics;
        int maxNum=0;
        for(int i=0;i<points.size();i++){
            statistics.clear();
            statistics[INT_MIN] = 0;
            int duplicate=1;
            for(int j=0;j<points.size();j++){
                if(j==i){continue;}
                if(points[j].x==points[i].x&&points[j].y==points[i].y) {
                    duplicate++;
                    continue;
                }
                float key=(points[i].x-points[j].x)==0?INT_MAX:(float)(points[j].y-points[i].y)/(points[j].x-points[i].x);
                statistics[key]++;
            }
            for (unordered_map<float, int>::iterator it = statistics.begin(); it != statistics.end(); ++it){
                if(it->second+duplicate>maxNum)maxNum=it->second+duplicate;
            }
        }
        return maxNum;
    }
};

