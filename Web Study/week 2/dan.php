<TABLE border = 1>
<?
	$gugudan = $_POST['gugu'];

	for ($i = 1; $i <= 9; $i++)
	{
		$result = $gugudan * $i;
		echo "<TR><TD>$gugudan * $i = $result </TD></TR><br>";
	}

?>
</TABLE>