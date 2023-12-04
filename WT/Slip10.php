<!--
Q.1) Write a script to accept two integers(Use html form having 2 textboxes). 
Write a PHP script to, 
a. Find mod of the two numbers. 
b. Find the power of first number raised to the second. 
c. Find the sum of first n numbers (considering first number as n) 
d. Find the factorial of second number. 
(Write separate function for each of the above operations.) 
-->

<!-- HTML FILE -->
<html>
    <body>
        <form action="setA1.php" method="GET">
            Enter Num_1 : <input type="number" name="n1"/>
            <br/>
            <br/>
            Enter Num_2 : <input type="number" name="n2"/>
            <br/>
            <br/>
            <input type="radio" name="op" value="1"/>
            1.mod of two number....
            <br/>
            <input type="radio" name="op" value="2"/>
            2.sum of two number....
            <br/>
            <input type="radio" name="op" value="3"/>
            3.factorial of second number....
            <br/>
            <input type="radio" name="op" value="4"/>
            4.power of first num raised to second number....
            <br/>
            <br/>
            <input type="submit"/>
        </form>
    </body>
</html>

<!-- PHP FILE -->
<?php
$a  = $_GET["n1"];
$b  = $_GET["n2"];
$ch = $_GET["op"];
echo "num_1 :".$a;
echo "<br>";
echo "num_2 :".$b;
echo "<br>";
echo "selected option is :".$ch;
echo "<br>";

switch ($ch)
{
    case 1:
        mod($a, $b);
        break;
    case 2:
        sum($a);
        break;
    case 3:
        factorial($b);
        break;
    case 4:
        power($a, $b);
        break;       
}

function mod($a, $b)
  {
    $md = $a % $b;
    echo "mod is : " .$md;
  }
echo "<br>";
function sum($a)
{
    $sm = 0;
    for ($i = 0; $i <= $a; $i++)
        $sm += $i;
    echo "sum is : " . $sm;
}
echo "<br>";
function factorial($b)
{
    $fact = 1;
    for ($i = 1; $i <= $b; $i++)
        $fact *= $i;
    echo "factorial of $b is : " . $fact;
}
function power($a, $b)
{
    $f = 1;
    $n = $b;
    for ($i = 1; $i <= $n; $i++)
        $f *= $a;
    echo "power of $a raised to $b is : " . $f;
}
?>