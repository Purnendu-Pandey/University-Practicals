<!---
Q.1) Write the HTML code for generating the form as shown below. Apply the internal CSS to 
following form to change the font size of the heading to 6pt and change the color to red and also 
change the background color to yellow.
-->
<html>
<head>
    <style>
        .main {
            width: 20%;
            height: auto;
            background-color: aqua;
            position: relative;
            margin: 100px;
            padding: 30px;
            border-radius: 8px;
        }
        .sub {
            background: yellowgreen;
            border-radius: 20% 20% 20% 20%;
            color: white;
        }
        .re {
            background: blue;
            border-radius: 20% 20% 20% 20%;
            color: white;
        }
    </style>
</head>
<body>
    <h1>Project Management</h1>
    <form action="">
        <div class="main">

            <div class="name">
                <label for="nm">Project Name: </label>
                <input type="text" name="nm" id="nm" required>
            </div>
            <br>
            <div class="assgn">
                <label for="ass">Assigned to: </label>
                <select name="a" id="ass">
                    <option value="1">Raj</option>
                    <option value="2">Sankalp</option>
                    <option value="3">Manas</option>
                </select>
            </div>
            <br>
            <div class="sd">
            <label for="d">Start Date</label>
                <input type="date" id="d">
            </div>
            <br>
            <div class="ed">
                <label for="e">End Date: </label>
                <input type="date" id="e">
            </div>
            <br>
            <div class="pri">
                <label for="p">Priority: </label>
                <input type="radio" name="priority">High
                <input type="radio" name="priority">Average
                <input type="radio" name="priority">Low
            </div>
            <br>
            <div class="dess">
                <label for="d">Description:</label>
                <textarea name="des" id="d" cols="10" rows="1"></textarea>
            </div>
            <br>
            <div class="btn">
                <input type="submit" name="Submit" class="sub">
                <input type="reset" value="Clear" class="re">
            </div>
        </div>
    </form>
</body>
</html>