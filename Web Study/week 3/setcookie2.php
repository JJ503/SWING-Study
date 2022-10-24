
	<?
		$result = setcookie("php", 'id', time()+1000);
		
		if ($result)
			echo "success";
		else
			echo "fail";
	?>