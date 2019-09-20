<?php
session_start();
function	get_data()
{
	if ((isset($_POST['login']) && $_POST['login'] != NULL) &&
		(isset($_POST['passwd']) && $_POST['passwd'] != NULL) &&
		(isset($_POST['submit']) && $_POST['submit'] === "OK"))
	{
		$tab['login'] = $_POST['login'];
		$tab['passwd'] = hash('sha256', $_POST['passwd']);
	}
	else
		exit("ERROR\n");
	return ($tab);
}
// Creates the path
$path = "../stored_hashes/private";
// You must store the accounts
$file = $path."/passwd";
// Grabs the data from the user input / hashes password
$tab = get_data();
if (!file_exists($path))
{
	mkdir ("../stored_hashes/");
	mkdir ($path);
}
if (!file_exists($file))
{
	$unserialized[] = $tab;
	$serialized[] = serialize($unserialized);
	file_put_contents($file, $serialized);
}
else
{
	$unserialized = unserialize(file_get_contents($file));
	foreach ($unserialized as $elem)
		foreach ($elem as $login=>$value)
			if ($value == $tab['login'])
				exit("ERROR\n");
	$unserialized[] = $tab;
	$serialized = serialize($unserialized);
	file_put_contents($file, $serialized);
}
echo "OK\n";
?>
