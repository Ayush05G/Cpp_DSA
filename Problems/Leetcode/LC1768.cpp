class Solution {
    public:
        string mergeAlternately(string word1, string word2) {
            string word;
            int l1=word1.length();
            int l2=word2.length();
             int j=0;
            int k=0;
            if(l1>=l2){
                for(int i=0;i<2*l2;i++){
                    if(i%2==0){
                        word+=word1[j++];
                    }
                    else{
                        word+=word2[k++];
                    }
                }
                while(j<word1.length()){
                    word+=word1[j++];
                }
            }
            else{
                for(int i=0;i<2*l1;i++){
                    if(i%2==0){
                        word+=word1[j++];
                    }
                    else{
                        word+=word2[k++];
                    }
                }
                while(k<word2.length()){
                    word+=word2[k++];
                }
    
            }
            return word;
            
        }
    };