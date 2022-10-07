import React from "react";
import "./Suggested.css";
import { Avatar, Button } from "@material-ui/core";
import { makeStyles } from "@material-ui/core/styles";
import InstagramIcon from "@material-ui/icons/Instagram";

const useStyles = makeStyles((theme) => ({
  root: {
    display: "flex",
    "& > *": {
      margin: theme.spacing(1),
    },
  },

  large: {
    width: theme.spacing(6.0),
    height: theme.spacing(6.0),
  },
}));

function Suggested() {
  const classes = useStyles();

  return (
    <div className="suggested">

    

  
      <h4>
        {" "}
        <InstagramIcon className="suggested_icon" /> Suggestions For You
      </h4>
      <p>
        Sed ut perspiciatis unde omnis iste natus err sit voluptatem iste
        natus error sit voluptatem{" "}
      </p>

      <div className="footer">
        <Avatar
          className="avatar"
          alt="Bhuban_Bam"
          src="https://mumbaimirror.indiatimes.com/photo/68636148.cms"
          className={classes.large}
        />

        <div className="footer_content">
          <h5>bbkivines_</h5>
        </div>
        <a href="https://www.instagram.com/bbkivines_/">
          <Button
            size="small"
            //   variant="contained"
            color="secondary"
            className="footer_follow"
          >
            Follow
          </Button>
        </a>
      </div>

      <div className="footer">
        <Avatar
          className="avatar"
          alt="sahidkapoor4"
          src="https://www.filmibeat.com/img/popcorn/profile_photos/shahid-kapoor-20190619173815-177.jpg"
          className={classes.large}
        />

        <div className="footer_content">
          <h5>sahidkapoor4</h5>
        </div>
        <a href="https://www.instagram.com/sahidkapoor4/">
          <Button
            size="small"
            //   variant="contained"
            color="secondary"
            className="footer_follow"
          >
            Follow
          </Button>
        </a>
      </div>

      <div className="footer">
        <Avatar
          className="avatar"
          alt="shirleysetia
          "
          src="https://m.media-amazon.com/images/M/MV5BMjMwZjhjOTUtNmVjNS00NTM1LWEwOTItN2ZlMzMwMGY5ZGQ2XkEyXkFqcGdeQXVyNDAzNDk0MTQ@._V1_.jpg"
          className={classes.large}
        />

        <div className="footer_content">
          <h5>shirleysetia</h5>
        </div>
        <a href="https://www.instagram.com/shirleysetia/">
          <Button
            size="small"
            //   variant="contained"
            color="secondary"
            className="footer_follow"
          >
            Follow
          </Button>
        </a>
      </div>

      <div className="footer">
        <Avatar
          className="avatar"
          alt="durjoydatta"
          src="https://images.newindianexpress.com/uploads/user/imagelibrary/2018/12/19/original/accidental.jpg"
          className={classes.large}
        />

        <div className="footer_content">
          <h5>durjoydatta</h5>
        </div>
        <a href="https://www.instagram.com/durjoydatta/">
          <Button
            size="small"
            
            color="secondary"
            className="footer_follow"
          >
            Follow
          </Button>
        </a>
      </div>

      <div className="footer">
        <Avatar
          className="avatar"
          alt="cristiano"
          src="https://encrypted-tbn0.gstatic.com/images?q=tbn%3AANd9GcQuZfZq9tllEgk_3z9bFGx-NLTS2vRcpSdB0Q&usqp=CAU"
          className={classes.large}
        />

        <div className="footer_content">
          <h5>cristiano</h5>
        </div>
        <a href="https://www.instagram.com/cristiano/">
          <Button
            size="small"
            
            color="secondary"
            className="footer_follow"
          >
            Follow
          </Button>
        </a>
      </div>


      <div className="footer">
        <Avatar
          className="avatar"
          alt="gameofthrones"
          src="https://www.skinillustrator.com/wp-content/uploads/2018/09/got-logo.jpg"
          className={classes.large}
        />

        <div className="footer_content">
          <h5>gameofthrones</h5>
        </div>
        <a href="https://www.instagram.com/gameofthrones/">
          <Button
            size="small"
            
            color="secondary"
            className="footer_follow"
          >
            Follow
          </Button>
        </a>
      </div>

      <a href="https://www.instagram.com/">
          <Button
            size="small"
            
            color="primary"
            className="footer_follow_main"
          >
            See All
          </Button>
    </a>


    </div>
  );
}

export default Suggested;
