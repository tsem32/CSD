Gialamoudis Anastasios 2910 (gialamoud)

Den exoun ulopoihthei deamons kai i/o redirection.

Ylopoihsh aplwn entolwn: H entolh pou dinei o xrhsths (metaxeirizetai ws string) pernietai ston parser o opoios th xwrizei vash tou kenou xarakthra.
Metepeita ta strings pou exoune prokupsei apothikevontai se ena 2d pinaka (args) opoios dinetai ws orisma sthn execv gia na ektelesei ths entoles.
paradeigma tetoias entolhs ls -l

Ylopoihsh cd: aplh ulopoihsh ths cd me xrhsh ths chdir. H entolh spaei se 2 komatia to cd kai to path kai apla kaloume th chdir me to path pou dwsame. p.x cd /home/gialamoud

Ylopoihsh exit: Dunamika an o xrhsths plhktrologisei th lexh exit to programma kalei tin exit(0) kai termatizei th leitourgia tou

Ylopoihsh pipe: Afou perasei h entolh ston parses kai spasei se kommatia elegxetai an mesa ston 2d pinaka pou proanefera periexetai o xarakthras |. Metepeita 
		xrhsimopoiwntas 2 sunarthseis pou egrapsa epistrefoume antistoixa to deksi meros tou  |  kai to aristero meros tou | etsi wste na mporw na kanw exec 
		autes tis 2 entoles. Exei fusika kalestei h pipe kai exoune ginei ta katalhla dup.
Ylopoihsh local variables: Xrhsimopoiw mia apla sundedemenh lista etsi wste na ginetai dunamikh h kataxwrhsh ton topikwn metavlitwn.Mesa sta paradwtea einai kai to interface ths.
		paradeigmaata xrhsimopoihshs:set,uset,printvars,echo, kai $:
		set var1=ls -l :dhmiourgei mia metavlith var1 pou periexei to string ls-l. Prosoxh kathws den einai set var1="ls -l" epeidh antimetwphsa duskolia sto parsarisma twn quotes logo xronou
		(polla deadlines).
		unset var1 : diagrafei thn metavlith var1.
		echo var1: tupwnei sthn othonei ls -l . To periexomeno ths dhladh.
		printvars : typwnei oles tis metavlites pou xw kanei set.
		$var1: tha ektelesei thn entolh ls- l.

