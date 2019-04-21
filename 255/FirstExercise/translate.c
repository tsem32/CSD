#include <stdio.h>


/*pinakas apo struct gia thn anaparastash xarakthrwn*/
struct {
 char anap[3];
}arr[255];

void init_arr(void){
  arr[168].anap[0]=34;
  arr[180].anap[0]=39;
  arr[181].anap[0]=39;
  arr[181].anap[1]=34;
  arr[182].anap[0]=39;
  arr[184].anap[0]=39;
  arr[184].anap[1]=69;
  arr[185].anap[0]=39;
  arr[185].anap[1]=72;
  arr[186].anap[0]=39;
  arr[186].anap[1]=73;
  arr[188].anap[0]=39;
  arr[188].anap[1]=79;
  arr[190].anap[0]=39;
  arr[190].anap[1]=89;
  arr[191].anap[0]=39;
  arr[191].anap[1]=87;
  arr[192].anap[0]=105;
  arr[192].anap[1]=34;
  arr[192].anap[2]=39;
  arr[193].anap[0]=65;
  arr[194].anap[0]=86;
  arr[195].anap[0]=71;
  arr[196].anap[0]=68;
  arr[197].anap[0]=69;
  arr[198].anap[0]=90;
  arr[199].anap[0]=72;
  arr[200].anap[0]=56;
  arr[201].anap[0]=73;
  arr[202].anap[0]=75;
  arr[203].anap[0]=76;
  arr[204].anap[0]=77;
  arr[205].anap[0]=78;
  arr[206].anap[0]=75;
  arr[206].anap[1]=83;
  arr[207].anap[0]=79;
  arr[208].anap[0]=80;
  arr[209].anap[0]=82;
  arr[211].anap[0]=83;
  arr[212].anap[0]=84;
  arr[213].anap[0]=89;
  arr[214].anap[0]=70;
  arr[215].anap[0]=88;
  arr[216].anap[0]=80;
  arr[216].anap[1]=83;
  arr[217].anap[0]=87;
  arr[218].anap[0]=34;
  arr[218].anap[1]=73;
  arr[219].anap[0]=34;
  arr[219].anap[1]=89;
  arr[220].anap[0]=97;
  arr[220].anap[1]=39;
  arr[221].anap[0]=101;
  arr[221].anap[1]=39;
  arr[222].anap[0]=104;
  arr[222].anap[1]=39;
  arr[223].anap[0]=105;
  arr[223].anap[1]=39;
  arr[224].anap[0]=121;
  arr[224].anap[1]=34;
  arr[224].anap[2]=39;
  arr[225].anap[0]=97;
  arr[226].anap[0]=118;
  arr[227].anap[0]=103;
  arr[228].anap[0]=100;
  arr[229].anap[0]=101;
  arr[230].anap[0]=122;
  arr[231].anap[0]=104;
  arr[232].anap[0]=56;
  arr[233].anap[0]=105;
  arr[234].anap[0]=107;
  arr[235].anap[0]=108;
  arr[236].anap[0]=109;
  arr[237].anap[0]=110;
  arr[238].anap[0]=107;
  arr[238].anap[1]=115;
  arr[239].anap[0]=111;
  arr[240].anap[0]=112;
  arr[241].anap[0]=114;
  arr[242].anap[0]=115;
  arr[243].anap[0]=115;
  arr[244].anap[0]=116;
  arr[245].anap[0]=121;
  arr[246].anap[0]=102;
  arr[247].anap[0]=120;
  arr[248].anap[0]=112; 
  arr[248].anap[0]=115;
  arr[249].anap[0]=119;
  arr[250].anap[0]=105;
  arr[250].anap[1]=34;
  arr[251].anap[0]=121;
  arr[251].anap[1]=34;
  arr[252].anap[0]=111;
  arr[252].anap[1]=39;
  arr[253].anap[0]=121;
  arr[253].anap[1]=39;
  arr[254].anap[0]=119;
  arr[254].anap[1]=39;
}

/*etkupwsh xarakthrwn*/

void printStream(int ch){
    int i=0;
    if(arr[ch].anap[i]=='\0'){
          putchar(ch);
    }else{ 
         while (arr[ch].anap[i]!='\0' && i<3){
           putchar(arr[ch].anap[i++]);
           
}
}
}

/*katastaseis automatou */
enum state{M,m,N,n,dntCr=0};

/* synarthsh gia thn katastash adiaforias (dn exoume n,N,m,M san prwto gramma) */
enum state arxikh(int ch){
    if(ch==204){
    return M;
    }else if(ch==236){
    return m;
    }else if(ch==205){
    return N;
    } else if(ch==237){
     return n;
   }else{
     printStream(ch);
     return dntCr;
}
}

enum state Mstate(int c){
      if(c==204){
        putchar(77);
        return M;
      }else if(c==236){
         putchar(77);
         return m;
       }else if(c==205){
         putchar(77);
         return N;
       }else if(c==237){
         putchar(77);
         return n;
      } else if(c==208){
          putchar(66);
          return dntCr;
     }else if(c==240){
          putchar(66);
          return dntCr;
     }else{
      putchar(77);
      printStream(c);
      return dntCr;
}
}

enum state mState(int c){
     if(c==204){
      putchar(109);
      return M;
     }else if(c==236){
      putchar(109);
      return m;
     }else if(c==205){
       putchar(109);
       return N;
     }else if(c==237){
       putchar(109);
       return n;
     }else if(c==208){
      putchar(98);
      return dntCr;
     }else if(c==240){
        putchar(98);
        return dntCr;
     }else{
        putchar(109);
        printStream(c);
        return dntCr;
}
}

enum state Nstate(int c){
    if(c==204){
       putchar(79);
       return M;
   }else if(c==236){
       putchar(79);
       return m;
   }else if(c==205){
     putchar(79);
      return N;
   }else if(c==237){
      putchar(79);
      return n;
   }else if(c==212){
      putchar(68);
      return dntCr;
   }else if(c==244){
         putchar(68);
	return dntCr;
    }else{
       putchar(79);
       printStream(c);
       return dntCr;
}
}


enum state nstate(int c){
    if(c==204){
      putchar(110);
      return M;
    }else if(c==236){
       putchar(110);
       return m;
    }else if(c==205){
       putchar(110);
       return N;
    }else if(c==237){
       putchar(110);
       return n;
    }else if(c==212){
        putchar(100);
        return dntCr;
    }else if(c==244){
         putchar(100);
         return dntCr;
    }else{
     putchar(110);
     printStream(c);
     return dntCr;
}
}
enum state (*state[])(int c) = 	{ arxikh,
									Mstate, mState,
									Nstate, nstate };


int main(void){
int c;
enum state  current;

init_arr();
current=dntCr;
while((c=getchar())!=EOF){
    current=(state[current])(c);
}
return 0;
}

