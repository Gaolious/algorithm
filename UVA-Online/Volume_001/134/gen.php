<?php
/*
sudo apt-get install libgmp-dev
sudo apt-get install php5-gmp
*/

class gen
{
	public function getChar()
	{
		return chr( ord('a') + rand(0,25) ) ;
	}
	public function getVowel()
	{
		$arr = array("a", "e", "i", "o", "u" );
		return $arr[ rand(0, count($arr)-1) ];
	}
	public function getConsonant()
	{
		$arr = array();
		for ( $i=ord('a') ; $i<=ord('z') ; $i++)
		{
			if ( $i == ord('a') ) continue ; 
			if ( $i == ord('e') ) continue ; 
			if ( $i == ord('i') ) continue ; 
			if ( $i == ord('o') ) continue ; 
			if ( $i == ord('u') ) continue ; 
			$arr[] = chr($i);
		}
		return $arr[ rand(0, count($arr)-1) ];
	}
	public function getA()
	{
		$arr = array("a", "e", "i", "o", "u" );
		return $arr[ rand(0, count($arr)-1) ];
	}
	public function getMOD()
	{
		$arr = array("ga", "ge", "gi", "go", "gu" );
		return $arr[ rand(0, count($arr)-1) ];
	}
	public function getBA()
	{
		$arr = array("ba", "be", "bi", "bo", "bu" );
		return $arr[ rand(0, count($arr)-1) ];
	}
	public function getDA()
	{
		$arr = array("da", "de", "di", "do", "du" );
		return $arr[ rand(0, count($arr)-1) ];
	}
	public function getLA()
	{
		$arr = array("la", "le", "li", "lo", "lu" );
		return $arr[ rand(0, count($arr)-1) ];
	}

	public function getNam()
	{
		$len = rand(1,10);
		
		$str = "";
		for ( $i = 0 ; $i < $len - 1 ; $i ++ ) $str .= $this->getChar();
		$str .= $this->getConsonant(); 
		return $str ;
	}
	public function GetPreda()
	{
		if ( rand(0,1) == 0 )
			return $this->getConsonant() . $this->getConsonant() . $this->getVowel() . $this->getConsonant() . $this->getVowel();
		else
			return $this->getConsonant() . $this->getVowel() . $this->getConsonant() .  $this->getConsonant() . $this->getVowel();
	}

	public function sentence()
	{
		if ( rand(0,1) == 0 ) return $this->statement();
		else return $this->predclaim();
	}
	public function predclaim()
	{
		if ( rand(0,1) == 0 )
			return $this->predname() . " ". $this->getBA() . " ".$this->preds();
		else
			return $this->getDA() . " ".$this->preds();
	}
	public function preds()
	{
		if ( rand(0,1) == 0 )
			return $this->predstring();
		else
			return $this->preds() . " ".$this->getA() . " ".$this->predstring();
	}
	public function predname()
	{
		if ( rand(0,1) == 0 )
			return $this->getLA() . " ".$this->predstring();
		else
			return $this->getNAM();
	}
	public function predstring()
	{
		if ( rand(0,1) == 0 )
			return $this->getPreda() ;
		else 
			return $this->predstring() . " ".$this->getPreda();
	}
	public function statement()
	{
		if ( rand(0,1) == 0 )
			return $this->predname() . " ".$this->verbpred() . " ".$this->predname();
		else
			return $this->predname() . " ".$this->verbpred();
	}
	public function verbpred()
	{
		return $this->getMOD() . " ".$this->predstring();
	}
}


$g = new gen();
$r = rand(10,100);
for ( $i = 0 ; $i < $r ; $i ++ )
{
	if ( rand(0,5) == 0 )
		echo $g->sentence() . $g->preds() . ".\n";
	else
		echo $g->sentence() . ".\n";
}
echo $g->verbpred() . ".\n";
echo $g->preds() . ".\n";
echo $g->predclaim() . ".\n";
