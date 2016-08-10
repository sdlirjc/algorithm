class Solution {
public:
	Solution();
	virtual ~Solution();
	int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
		int area1 = (D-B)*(C-A);
		int area2 = (H-F)*(G-E);
		if(min(H,D)<max(B,F)||min(C,G)<max(A,E)){
			return abs(area1) + abs(area2);
		}else{
			int dX=min(H,D)-max(B,F);
			int dY=min(C,G)-max(A,E);
			return abs(area1) + abs(area2) - abs(dY*dX);
		}
	}
};

