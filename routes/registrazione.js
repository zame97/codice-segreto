'use strict';

//routes della pagina di sign up


const express = require('express');
const router = express.Router();
const app = require('../app');

router.get('/', function(req, res, next) {
    res.render('registrazione');
});

router.post('/', function(req, res, next) {
    
});

module.exports = router;