/** Segment Intersection */ 


typedef long long ll;

struct pt{
 ll x;
 ll y;
}pt1,pt2,pt3,pt4;
ll d1,d2,d3,d4;
 
ll CROSS_PRODUCT( pt p1 , pt p2 )
  {
     return (p1.x * p2.y) - (p2.x * p1.y);
  }
ll DIR(pt i , pt j ,pt k)
   {
     pt temp1;
     pt temp2;
     temp1.x = k.x - i.x ; temp1.y = k.y - i.y;
     temp2.x = j.x - i.x ; temp2.y = j.y - i.y;
     return CROSS_PRODUCT(temp1,temp2);
   }
bool ON_SEG(pt i, pt j, pt k)
{
  if((min(i.x , j.x) <= k.x && k.x <= max(i.x , j.x)) && ( min(i.y , j.y) <= k.y && k.y <= max(i.y , j.y) ))
    return true;
   return false;
}
bool SEG_INT()
{
   d1 = DIR(pt3,pt4,pt1);
   d2 = DIR(pt3,pt4,pt2);
   d3 = DIR(pt1,pt2,pt3);
   d4 = DIR(pt1,pt2,pt4);
  // cout<<d1<<d2<<d3<<d4<<endl;
     if(((d1 > 0 && d2 < 0)||( d1 < 0 && d2 > 0 )) && ((d3 > 0 && d4 < 0)||(d3 < 0 && d4 >0)))
          return true;
     if ( d1 == 0 && ON_SEG(pt3,pt4,pt1) )
           return true;
     if ( d2 == 0 && ON_SEG(pt3,pt4,pt2) )
           return true;
     if ( d3 == 0 && ON_SEG(pt1,pt2,pt3) )
           return true;
     if ( d4 == 0 && ON_SEG(pt1,pt2,pt4) )
           return true;
    return false;
}
int main()
{
  
          cin>>pt1.x>>pt1.y>>pt2.x>>pt2.y;
          cin>>pt3.x>>pt3.y>>pt4.x>>pt4.y;

              bool flag = (pt1.x == pt2.x && pt1.y == pt2.y) || (pt3.x == pt4.x && pt3.y == pt4.y);
              bool ans = SEG_INT();
        


      /*  if(ans == true)   Only needed if want to be specific 
         { if(flag)
             {cout<<"POINT"<<endl;continue;}
          if(d1 == 0 && d2 == 0 && d3 == 0 && d4 == 0)
             { vector<int>arr1(4);
               arr1[0]=pt1.x;  arr1[1]=pt2.x;  arr1[2]=pt3.x;  arr1[3]=pt4.x;
               vector<int>arr2(4);
                arr2[0]=pt1.y;  arr2[1]=pt2.y;  arr2[2]=pt3.y;  arr2[3]=pt4.y;
               sort(arr1.begin(),arr1.end());
               sort(arr2.begin(),arr2.end());
              if(abs(arr1[2]-arr1[1]) + abs(arr2[2]-arr2[1]) !=0)
                 {cout<<"SEGMENT"<<endl;continue;}
              }
              cout<<"POINT"<<endl;
         }
        else
          cout<<"NO"<<endl;

      */    
      
}