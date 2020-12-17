<?php
	//вариант 3
	$num = 20;
	
	$X = [];	
	
	$A = 6; 
	$B = 8; 
	$M = 11; 
	$N = 10; 
	$X0 = 2;
	
	function f($i) {
		if ($i == 0) {
			$GLOBALS["X"][$i] = $GLOBALS["X0"];
			return $GLOBALS["X"][$i];
		}
		
		$GLOBALS["X"][$i] = ($GLOBALS["A"] * f($i - 1) + $GLOBALS["B"]) % $GLOBALS["M"];
		return $GLOBALS["X"][$i];
	}
	
	echo '<ul>';
	for ($i = $N; $i <= $num; $i++)
		echo '<li>' . $i . '</li>';
	
	echo '</ul><marquee bgcolor="FireBrick" behavior="alternate" direction="right">Иванова Карина ОТЧЕСТВО ' . date('d.m.20y') . '</marquee><table border="1">';
	
	f(5);
	
	for ($i = 0; $i < 5; $i++)
		echo '   
		<tr>
			<th>' . ($i + $N) . '</th>
			<th>' . $X[$i] . '</th>
		</tr>';
	
	echo '</table>';
	
?> 

