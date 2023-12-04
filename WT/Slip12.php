<!--
Q.1) Write a PHP script for the following: Design a form to accept two numbers from the user. 
Give options to choose the arithmetic operation (use radio buttons). Display the result on the next 
form. (Use the concept of function and default parameters. Use ‘include’ construct or require 
statement)
-->

<!--HTML FILE -->

<html>
<body>
    <form action="S12.php" method="post">
        enter a:
        <input type="int" name="a"><br>
        enter b:
        <input type="int" name="b"><br>
        Choose the Arithmetic oprtns :<br>
        1:'+'
        <input type="radio" name="op" value="1"><br>
        2:'-'
        <input type="radio" name="op" value="2"><br>
        3:'/'
        <input type="radio" name="op" value="3"><br>
        4:'*'
        <input type="radio" name="op" value="4"><br>
        <input type="submit" value="Submit">
    </form>
</body>
</html>

<!--PHP FILE -->
<?php
$a=$_POST['a'];
$b=$_POST['b'];
$op=$_POST['op'];
switch($op)
{
    case 1:$c=$a+$b;
        echo" addition : $c";
        break;
        case 2:$c=$a-$b;
        echo" subtraction : $c";
        break;
        case 3:$c=$a/$b;
        echo" Division : $c";
        break;
        case 4:$c=$a*$b;
        echo" Multiplication : $c";
        break;
}
?>