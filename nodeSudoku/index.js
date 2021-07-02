const express = require('express')
const {spawn} = require('child_process');
const ejs = require('ejs');
const app = express();
var multer = require('multer');
app.set('view engine', 'ejs');
app.use(express.json());
app.use(express.urlencoded({
  extended: true
}));


const port = 3000;

app.use(express.static(__dirname + '/public'));

var uploaded = "";
var Storage = multer.diskStorage({
    destination: function(req, file, callback) {
        callback(null, "./public");
    },
    filename: function(req, file, callback) {
        uploaded = file.fieldname + "_" + Date.now() + "_" + file.originalname;
        callback(null, file.fieldname + "_" + Date.now() + "_" + file.originalname);
    }
});

app.get("/page", function(req, res) {
    res.sendFile(__dirname + "/public/index.html");
});

var upload = multer({
    storage: Storage
}).array("imgUploader", 3); //Field name and max count

app.post("/api/Upload", function(req, res) {
    upload(req, res, function(err) {
        if (err) {
            return res.end("Something went wrong!");
        }
        res.redirect('/solve');
    });
});
app.get('/solve', (req, res) => {


    var dataToSend;
    // spawn new child process to call the python script
    const python = spawn('python', ['script.py' , uploaded]);
    // collect data from script
    python.stdout.on('data', function (data) {
    console.log('Pipe data from python script ...');
    dataToSend = data.toString();
    });
    // in close event we are sure that stream from child process is closed
    python.on('close', (code) => {
        console.log(`child process python close all stdio with code ${code}`);
        // send data to browser
        //res.sendFile(__dirname + '/public/sudoku.txt');
        const cpp = spawn('index.exe');
        cpp.stdout.on('data', function (data) {
            console.log('Pipe data from cpp script ...');
            dataToSend = data.toString();
        });
        cpp.on('close', (code) => {
            console.log(`child process cpp close all stdio with code ${code}`);
            // send data to browser
            res.sendFile(__dirname + '/inputText/result.txt');
        });
    });
    

});
app.listen(port, () => console.log(`Example app listening on port 
${port}!`))