<?php
	//вариант 4
	$var = 4; //номер студента
	$ARR = []; //массив для хранения равномерно-распределенных чисел
	
    //значения для варианта
	$ARR0 = 1;	    
	$A = 7; 
	$B = 9; 
	$M = 17; 
	$N = 11; 
	
	function f($i) { //рекрсивная функция для расчета равномерно-распределенных чисел
		if ($i == 0) {
			$GLOBALS["ARR"][$i] = $GLOBALS["ARR0"]; //ассоциативный массив $GLOBALS для обращения к глобальным переменным
			return $GLOBALS["ARR"][$i];
		}
		
		$GLOBALS["ARR"][$i] = ($GLOBALS["A"] * f($i - 1) + $GLOBALS["B"]) % $GLOBALS["M"]; //рекуррентная формула
		return $GLOBALS["ARR"][$i];
	}
	
	f(5); //вызов рекурсивной функции, которая генерирует равномерно-распределенных чисел
	
	echo '<ul>';
	for ($i = $N; $i > $var; $i--) //код, создающий список
		echo '<li>' . $i . '</li>';
	
	echo '</ul><marquee bgcolor="DarkRed" behavior="alternate" direction="right">Донин Андрей Алексеевич ' . date('d.m.20y') . '</marquee><table border="1">'; //бегущая строка
	
	
	for ($i = 0; $i < 5; $i++) //код, создающий таблицу
		echo '   
		<tr>
			<th>' . ($N - $i) . '</th>
			<th>' . $ARR[$i] . '</th>
		</tr>';
	
	echo '</table>';
	
?>
