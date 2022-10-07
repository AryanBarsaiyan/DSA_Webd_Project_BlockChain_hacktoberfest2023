import React from "react";
import "./Story.css";
import { Avatar } from "@material-ui/core";
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

function Story() {
  const classes = useStyles();

  return (
    <div className="story">
      <div className="story__item">
        <Avatar
          className="avatar"
          alt="subhampreet"
          src="/images/avatar.jpg"
          className={classes.large}
        />
        <h6>subhampreet</h6>
      </div>

      <div className="story__item">
        <Avatar
          className="avatar"
          alt="subhampreet"
          src="https://encrypted-tbn0.gstatic.com/images?q=tbn%3AANd9GcQ7X1a5uXND5eV1xt1ihm1RqafYqZ2_iFAWeg&usqp=CAU"
          className={classes.large}
        />
        <h6>subhampreet</h6>
      </div>

      <div className="story__item">
        <Avatar
          className="avatar"
          alt="subhampreet"
          src="https://miro.medium.com/max/2048/0*0fClPmIScV5pTLoE.jpg"
          className={classes.large}
        />
        <h6>subhampreet</h6>
      </div>

      <div className="story__item">
        <Avatar
          className="avatar"
          alt="subhampreet"
          src="https://encrypted-tbn0.gstatic.com/images?q=tbn%3AANd9GcRBwgu1A5zgPSvfE83nurkuzNEoXs9DMNr8Ww&usqp=CAU"
          className={classes.large}
        />
        <h6>subhampreet</h6>
      </div>

      <div className="story__item">
        <Avatar
          className="avatar"
          alt="subhampreet"
          src="https://images.unsplash.com/photo-1518806118471-f28b20a1d79d?ixlib=rb-1.2.1&ixid=eyJhcHBfaWQiOjEyMDd9&w=1000&q=80"
          className={classes.large}
        />
        <h6>subhampreet</h6>
      </div>

      <div className="story__item">
        <Avatar
          className="avatar"
          alt="subhampreet"
          src="https://i.pinimg.com/736x/0e/c6/6b/0ec66b439eb296c4f69cc261e44a785b.jpg"
          className={classes.large}
        />
        <h6>Subhampreet</h6>
      </div>
    </div>
  );
}

export default Story;
