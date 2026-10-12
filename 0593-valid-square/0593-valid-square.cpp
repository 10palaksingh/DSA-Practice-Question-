class Solution {
public:
int d(vector<int>p1,vector<int>p2){
                
            int dis=(((p1[0]-p2[0])*(p1[0]-p2[0]))+((p1[1]-p2[1])*(p1[1]-p2[1])));
            return dis;

}
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        if(p1==p2||p1==p3||p1==p4||p2==p3||p2==p4||p3==p4)return false;
         vector<int>x;
         x.push_back(d(p1,p2));
         x.push_back(d(p1,p3));
         x.push_back(d(p1,p4));
         x.push_back(d(p2,p3));
         x.push_back(d(p2,p4));
         x.push_back(d(p3,p4));
         sort(x.begin(),x.end());
         if(x[0]==x[1]&&x[2]==x[1]&&x[2]==x[3]&&x[4]==x[5]&&x[0]!=x[4]){
            return true;
         }
     return false;     
    }
};