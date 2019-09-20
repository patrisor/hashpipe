<?php
    if ($_POST['login'] && $_POST['oldpw'] && $_POST['newpw'] && $_POST['submit'] && $_POST['submit'] === "OK") {
		$account = unserialize(file_get_contents('../stored_hashes/private/passwd'));
		if ($account) {
			$exist = 0;
			foreach ($account as $k => $v) {
				if ($v['login'] === $_POST['login'] && $v['passwd'] === hash('sha256', $_POST['oldpw'])) {
					$exist = 1;
					$account[$k]['passwd'] = hash('sha256', $_POST['newpw']);
				}
			}
			if ($exist) {
				file_put_contents('../stored_hashes/private/passwd', serialize($account));
				echo "OK\n";
			} else
				echo "ERROR\n";
		} else
			echo "ERROR\n";
	} else
		echo "ERROR\n";
?>
