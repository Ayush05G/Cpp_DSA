class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        //P truck
        int pickP = 0;
        int travelP = 0;
        int lastHouseP = 0;

        //M Truck
        int pickM = 0;
        int travelM = 0;
        int lastHouseM = 0;
        
        //G Truck
        int pickG = 0;
        int travelG = 0;
        int lastHouseG = 0;

        //let's travel to the street of houses
        for(int i=0; i<garbage.size(); i++) {
            //ith House
            string currHouse = garbage[i];
            //let dive in into current house and see the type of garbage present
            for(int j=0; j<currHouse.length(); j++) {
                char garbageType = currHouse[j];
                if(garbageType == 'P') {
                    pickP++;
                    //yaha tk toh mera P truck pkka aaya h, toh let's tore it
                    lastHouseP = i;
                }
                if(garbageType == 'M') {
                    pickM++;
                    lastHouseM = i;
                }
                if(garbageType == 'G') {
                    pickG++;
                    lastHouseG = i;
                }
            }
        }
         //let's calculate travet time for P
            for(int i=0; i<lastHouseP; i++) {
                travelP = travelP + travel[i];
            }

             //let's calculate travet time for G
            for(int i=0; i<lastHouseG; i++) {
                travelG = travelG + travel[i];
            }

             //let's calculate travet time for M
            for(int i=0; i<lastHouseM; i++) {
                travelM = travelM + travel[i];
            }

            int totalPickingTime = pickP + pickM + pickG;
            int totalTravelTime = travelP + travelG + travelM;

            int totalTime = totalPickingTime + totalTravelTime;
            return totalTime;

    }
};