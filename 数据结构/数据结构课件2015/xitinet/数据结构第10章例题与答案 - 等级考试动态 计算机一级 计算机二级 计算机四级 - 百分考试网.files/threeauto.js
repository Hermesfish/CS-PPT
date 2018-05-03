function ZD_colH(){ 
  var i,oh,hh,h=0,dA=document.zdeqc,an=document.zdeqa;
  if(dA&&dA.length){
    for(i=0;i<dA.length;i++){
   dA[i].style.height='auto';
    }
 for(i=0;i<dA.length;i++){
      oh=dA[i].offsetHeight;h=(oh>h)?oh:h;
 }
 for(i=0;i<dA.length;i++){
   if(an){
        dA[i].style.height=h+'px';
   }else{
     ZD_eqA(dA[i].id,dA[i].offsetHeight,h);
   }
 }
 if(an){
      for(i=0;i<dA.length;i++){
     hh=dA[i].offsetHeight;
  if(hh>h){
          dA[i].style.height=(h-(hh-h))+'px';
  }
   }
 }else{
   document.zdeqa=1;
 }
    document.zdeqth=document.body.offsetHeight;
    document.zdeqtw=document.body.offsetWidth;
  }
}

function ZD_eqT(){ 
  if(document.zdeqth!=document.body.offsetHeight||document.zdeqtw!=document.body.offsetWidth){
    ZD_colH();
  }
}

function ZD_equalCols(){ 
  if(document.getElementById){
    document.zdeqc=new Array;
    for(i=0;i<arguments.length;i++){
      document.zdeqc[i]=document.getElementById(arguments[i]);
    }
 setInterval("ZD_eqT()",10);
  }
}

function ZD_eqA(el,h,ht){ 
  var sp=10,inc=10,nh=h,g=document.getElementById(el),oh=g.offsetHeight,ch=parseInt(g.style.height);
  ch=(ch)?ch:h;var ad=oh-ch,adT=ht-ad;nh+=inc;nh=(nh>adT)?adT:nh;g.style.height=nh+'px';
  oh=g.offsetHeight;if(oh>ht){nh=(ht-(oh-ht));g.style.height=nh+'px';}
  if(nh<adT){
    setTimeout("ZD_eqA('"+el+"',"+nh+","+ht+")",sp);
  }
}