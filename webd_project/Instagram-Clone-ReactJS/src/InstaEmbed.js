import React from "react";
import "./InstaEmbed.css";
import CopyrightIcon from '@material-ui/icons/Copyright';
import { Avatar, Button } from "@material-ui/core";
import { makeStyles } from "@material-ui/core/styles";


const useStyles = makeStyles((theme) => ({
    root: {
      display: "flex",
      "& > *": {
        margin: theme.spacing(1),
      },
    },
  
    large: {
      width: theme.spacing(8),
      height: theme.spacing(8),
    },
  
   
  }));

function InstaEmbed() {

    const classes = useStyles();


  return (
    <div className="instaEmbed">
      <img src="/images/header2.png" className="embed_image" />
      <div className="embedText">
        <h4>Hello Peeps 👋 !!!</h4>
        <h4>Welcome to Instagram Clone App ⚡ !!!</h4>

        <p>
          Instagram is an American photo and video sharing social networking service owned by Facebook. This project is a Clone of the original Instagram UI. This Project provides some basic features, similar to the original application.
          <br />
          <br />
          <b>P.S.</b> This project has been developed for learning purposes, and it has nothing to do with the original Application.
          <br />
          <br />
          <b>Features : </b>
          <ul>
            <li>User Authentication : Sign In and Sign Up</li>
            <li>Image Uploading for creating new Posts</li>
            <li>User can add Comments to the Posts</li>
            <li>An Awesome User-Interface</li>
          </ul>
          <br />
        </p>
        <h4>Hope you have a great time, exploring the application in and out ✌ !!!</h4>
      </div>

      <div className="footer">
        <Avatar
          className="avatar"
          alt="subhampreet"
          src="/images/avatar.jpg"
          className={classes.large}
        />

        <div className="footer_content" >
            <h5>Subhampreet Mohanty</h5>
            <a href="https://www.instagram.com/_the.odist_/"><Button variant="contained" color="secondary" className="footer_follow" >Follow</Button></a>
        </div>

        
      </div>
      <div className="copyright">
            <CopyrightIcon fontSize="small" className="copyright_icon" />2020 INSTAGRAM-CLONE BY SUBHAMPREET 
      </div>
    </div>
  );
}

export default InstaEmbed;
