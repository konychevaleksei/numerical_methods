<?php
	//вариант 2
	$variant = 2; //номер студента
	$array = []; //массив для хранения равномерно-распределенных чисел
	
    //значения констант для варианта
	$A = 5; 
	$B = 7; 
	$M = 13; 
	$N = 9; 
	$array0 = 1;
	
	function f($i) { //используем рекрсивную функцию для расчета равномерно-распределенных чисел
		if ($i == 0) {
			$GLOBALS["array"][$i] = $GLOBALS["array0"]; //используем ассоциативный массив $GLOBALS для обращения к глобальным переменным
			return $GLOBALS["array"][$i];
		}
		
		$GLOBALS["array"][$i] = ($GLOBALS["A"] * f($i - 1) + $GLOBALS["B"]) % $GLOBALS["M"]; //рекуррентная формула
		return $GLOBALS["array"][$i];
	}
	
	f(5); //вызов рекурсивной функции для генерирования равномерно-распределенных чисел
	
	echo '<ul>';
	for ($i = $N; $i > $variant; $i--) //реализация списка
		echo '<li>' . $i . '</li>';
	
	echo '</ul><marquee bgcolor="Red" behavior="alternate" direction="right">Величко Никита Дмитриевич ' . date('d.m.20y') . '</marquee><table border="1">'; //бегущая строка
	
	
	for ($i = 0; $i < 5; $i++) //реализация таблицы
		echo '   
		<tr>
			<th>' . ($N - $i) . '</th>
			<th>' . $array[$i] . '</th>
		</tr>';
	
	echo '</table>';
	
?>
