<html>
<body>
<table border = 1>
<?
	$dan = $_POST['dan'];

	for ($n = 1; $n <= 9; $n++)
	{
		echo "<tr>";

		for ($i = $dan; $i <= 9; $i++)
		{
			$result = $i * $n;
			echo "<td> $i * $n = $result </td>";
		}
		
		echo "</tr>";
	}
?>
</table>
</body>
</html>