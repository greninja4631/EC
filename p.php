<?php
function greet($name)
{
    echo "Hello, " . $name . "!";
}
$users = ["Alice", "Bob", "Charlie"];
foreach ($users as $user) {
    greet($user);
    if ($user === "Bob") {
        echo " - Special user!";
    }
}
