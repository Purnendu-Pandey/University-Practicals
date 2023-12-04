<!--
Q.1) Design an HTML form to accept two strings from the user. Write a PHP script for the 
following.
a. Find whether the small string appears at the start of the large string. 
b. Find the position of the small string in the big string. 
c. Compare both the string for first n characters, also the comparison should not be case 
sensitive. 
-->

<!-- HTML FILE -->
<html>
   <body>
      <form action=".php" method="GET">
         Enter first String : <input type="text" name="n1" />
         <br />
         <br />
         Enter second String : <input type="text" name="n2" />
         <br />
         <br />
         <input type="radio" name="op" value="1" />
         1.small string is at start of big string....
         <br />
         <input type="radio" name="op" value="2" />
         2.position of small string in big string....
         <br />
         <input type="radio" name="op" value="3" />
         3.compare both string for n character(comparision case insensitive)...
         <br />
         <br />
         <input type="submit" />
      </form>
   </body>
</html>

<!-- PHP FILE -->
<?php
$str1 = $_GET["n1"];
$str2 = $_GET["n2"];
$ch = $_GET["op"];
echo "Entered string_1 is : ".$str1;
echo "<br>";
echo "Entered string_2 is : ".$str2;
echo "<br>";
echo "selected option is : ".$ch;
echo "<br>";

switch ($ch)
{
    case 1:
        sml_at_start($str1, $str2);
        break;
    case 2:
        sml_pos_in_bigstr($str1, $str2);
        break;
    case 3:
        comp_n_char($str1, $str2);
        break;
}
function sml_at_start($str1, $str2) 
{
    $pos = strpos($str1, $str2);
    if ($pos === 0)
    {
        echo "string $str2 is found at start and its position is : " .($pos + 1);
    }
    else
    {
        echo "string $str2 is not found at starting position ";
    }
}
echo "<br>";

function sml_pos_in_bigstr($str1, $str2) 
{
    $p = strpos($str1, $str2);
    if ($p !== false) 
    {
        echo "  string $str2 is found at position  : " . ($p + 1);
    } 
    else 
    {
        echo "  string $str2 is not found  ";
    }
}

echo "<br>";

function comp_n_char($str1, $str2)
{
    $po = strncasecmp($str1, $str2, 10);
    if ($po == 0) 
    {
        echo " Both strings are equal  : ";
    }
    else
    {
        echo " Both strings are not equal  ";
    }
}
?>