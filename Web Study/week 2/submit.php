<?
	$name = $_POST['name'];
	$password = $_POST['mypassword'];
	$sex = $_POST['sex'];
	$ha = $_POST['ha'];
	$pre = $_POST['pre'];

	echo "이름 : $name <br>";
	echo "비밀번호 : $password <br>"; 

	switch ($sex) {
	case "남":
		echo " 성별 : $sex<br>";
		break;
	case "여":
		echo "성별 : $sex <br>";
		break;
	}

	switch ($ha) {
	case "독서":
		echo "취미 : $ha <br>";
		break;
	case "음악감상":
		echo "취미 : $ha <br>";
		break;
	case "걷기":
		echo "취미 : $ha <br>";
		break;
	}

	echo "자기소개 : $pre"
?>