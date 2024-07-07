class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
      int consumed=numBottles;
      int empty=numBottles;
      while(empty>=numExchange){
        int extra=empty/numExchange;
        int remain=empty%numExchange;
        consumed+=extra;
        empty=remain+extra;
      }
      return consumed;
      
    }
};