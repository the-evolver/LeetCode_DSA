class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
   
    	for(int t=0; t<9; t++){
    		vector<char> vv = board[t];
    	    std::sort(vv.begin(), vv.end());
    	    for(int a=0; a<8; a++){
    	        if(vv[a] == vv[a+1] && vv[a] != '.'){
    	        	return false;
    	        }
    	    }
    	}
       for(int i=0; i<9; i+=3) { 
	        for(int j=0; j<9; j+=3) {
	            vector<char> control;
	            for(int k=0; k<3; k++) {
	                for(int l=0; l<3; l++) {
	                    control.push_back(board[i+k][j+l]);
	                }
	            }
	            sort(control.begin(), control.end()); 
	            for(int k=1; k<control.size(); k++) {
	                if(control[k] == control[k-1] && control[k] != '.') {
	                    return false; 
	                }
	            }
	        }
    	}
    	for(int j=0; j<9; j++) { 
	        vector<char> control2;
	        for(int i=0; i<9; i++) {
	            control2.push_back(board[i][j]);
	        }
	        sort(control2.begin(), control2.end()); 
	        for(int k=1; k<control2.size(); k++) {
	            if(control2[k] == control2[k-1] && control2[k] != '.') {
	                return false; 
	            }
	        }
    	}
    	
    	return true;
    }
};