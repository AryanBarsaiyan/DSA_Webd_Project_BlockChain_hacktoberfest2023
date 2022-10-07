
import firebase from "firebase";

const firebaseApp = firebase.initializeApp({
    apiKey: "AIzaSyBKM_qJm7k2kHhSA1GbGEXHNzQc6E8wfmQ",
    authDomain: "instagram-clone-react-70113.firebaseapp.com",
    databaseURL: "https://instagram-clone-react-70113.firebaseio.com",
    projectId: "instagram-clone-react-70113",
    storageBucket: "instagram-clone-react-70113.appspot.com",
    messagingSenderId: "375283177912",
    appId: "1:375283177912:web:ae590d1e7bf10a800b574d",
    measurementId: "G-GR8GZJQZ3L"

});

const db = firebaseApp.firestore();
const auth = firebase.auth();
const storage = firebase.storage();

export { db, auth, storage };