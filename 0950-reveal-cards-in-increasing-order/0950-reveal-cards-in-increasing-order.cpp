class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n= deck.size();
        
        vector<int> sortedDeck= deck;
        sort(sortedDeck.begin(),sortedDeck.end(),greater<int>());
        
        
        // Simulate the process to get Alternate Parity
        
        deque<int> dq;
        dq.push_front(sortedDeck[0]);
        
        for(int i=1;i<n;i++){
            
            dq.push_front(dq.back());
            dq.pop_back();
            dq.push_front(sortedDeck[i]);
        }
        
        
        vector<int> res;
        while(!dq.empty()){
            
            res.push_back(dq.front());
            dq.pop_front();
        }
        
        
        return res;
    }
};