// englconv.cpp
// conversions: Distance to meters, meters to Distance
#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////
class Distance                    //English Distance class
   {
   private:
      float MTF;            //meters to feet
      int feet;
      float inches;
   public:                        //constructor (no args)
      Distance() : feet(0), inches(0.0), MTF(3.280833F)      
         {  }                     //constructor (one arg)
                        //constructor (two args)
        Distance(float meters) : MTF(3.280833F) 
         {                        //convert meters to Distance
         float fltfeet = MTF * meters;  //convert to float feet
         feet = int(fltfeet);           //feet is integer part
         inches = 12*(fltfeet-feet);    //inches is what's left
         }   
      Distance(int ft, float in) : feet(ft), 
                                      inches(in), MTF(3.280833F)
         {  }
      void getdist()              //get length from user
         {
         cout << "\nEnter feet: ";  cin >> feet;
         cout << "Enter inches: ";  cin >> inches;
         }
      void showdist() const       //display distance
         { cout << feet << "\'-" << inches << "\""; }//or '\"'

      operator float() const      //conversion operator
         {                        //converts Distance to meters
         float fracfeet = inches/12;     //convert the inches
         fracfeet += static_cast<float>(feet); //add the feet
         return fracfeet/MTF;            //convert to meters
         }
         
         
   };
     
////////////////////////////////////////////////////////////////
int main()
   {
   float mtrs;
   //float k=2.35;//mine
   Distance dist1 = 2.35F;        //uses 1-arg constructor to
                                  //convert meters to Distance
      //  Distance dist3;//mine
	//	dist3= 2.35; //mine                       
   cout << "\ndist1 = "; dist1.showdist();
   mtrs = static_cast<float>(dist1); //uses conversion operator
               cout<<mtrs<<endl;                      //for Distance to meters 
   cout << "\ndist1 = " << mtrs << " meters\n";
   Distance dist2(5, 10.25);      //uses 2-arg constructor
   cout<<"dist2=";
   dist2.showdist(); 
   cout<<endl;                  //mine
   mtrs = dist2;                  //also uses conversion op                                    
   cout << "\ndist2 = " << mtrs << " meters\n";
    mtrs=1.2F;
   dist2 = mtrs;
   cout<<"dist2=";
   dist2.showdist();                   //mine
   cout<<dist2;           //TO MAKE THIS POSSIBLE WE HAVE TO DEFINE A CONVERSION 
   //OPERTAOR FOR TYPE DISTANE ,LIKE WE DID FOR FLOAT.
        //error, = won't convert
   return 0;
   }
   //the conversiion operator needs to be defined..for this to work this is the case
   //SOME CONCLUSIINAS FROM THE OTHER CASES AS OF TIME::
   	//1.THE DEST NEEDS TO HAVE A CONSTUCTOR FOR COVNVERSION as data access needed
    //2.THE SOURCE CANT HAVE CONSTRUCTOR AS IT IS ON THE RIGHT.
	//3.THE SOURCE SHOULD HAVE A CONV OPERATOR(BOTH WORKS FOR BOTH CASES(IMPORTANT)) 
	//4.AND SINCE ACCESS IS NEEDED THE DEST CANT EVEN HAVE A CONV OPERATOR
	//doubt (including clarification for what stated above )
	//removing the const from the data member makes it work.......
   //IMPOTRANT CONCEPT
   //(66)THE COMPLIER LOOKS FOR SOME CONVEERSON AS IT KNOWS NOTHG ABOUT HTE DISTANE CLASS
  // and fnds...........................................
