import React, { useState } from "react";
const Contact = () => {
  const [user, setUser] = useState({
    name: "",
    email: "",
    phone: "",
    address: "",
    message: "",
  });
  let name, value;
  const getuserData = (event) => {
    name = event.target.name;
    value = event.target.value;
    setUser({ ...user, [name]: value });
  };
  const postData = async (e) => {
    e.preventDefault();
    const { name, email, phone, address, message } = user;
    if (name && email && phone  && message) {
      const res = await fetch(
        "https://messanger-8eccb-default-rtdb.firebaseio.com/messanger.json",
        {
          method: "POST",
          headers: { "Content-Type": "application/json" ,},
          body: JSON.stringify({ name, email, phone, address, message }),
        }
      );
      if (res) {
        setUser({ name: "", email: "", phone: "", address: "", message: "" });
        alert("Thanks For Filling Form ! Data Saved Successfully.");
      }
    } else alert("please fill data");
  };
  return (
    <>
    <div className="container">
      <h1 className="headingg">Hi Welcome to PJudge</h1>
      <h3 className="headin">Add Your Response to Community For Better Result</h3>
    </div>
      <div className="container-contact100">
        <div className="wrap-contact100">
          <form className="contact100-form" method="POST">
            <span className="contact100-form-title">Raise Voice</span>
            <div className="wrap-input100rs1-wrap-input100">
              <span className="label-input100">Your Name</span>
              <input
                className="input100"
                type="text"
                name="name"
                placeholder="Enter your name"
                value={user.name}
                onChange={getuserData}
                autoComplete="off"
                required
              />
              <span className="focus-input100"></span>
            </div>

            <div className="wrap-input100rs1-wrap-input100">
              <span className="label-input100">Email</span>
              <input
                className="input100"
                type="text"
                name="email"
                placeholder="Enter your email address"
                value={user.email}
                onChange={getuserData}
                autoComplete="off"
                required
              />
              <span className="focus-input100"></span>
            </div>
            <div className="wrap-input100rs1-wrap-input100">
              <span className="label-input100">Mobile Number</span>
              <input
                className="input100"
                type="text"
                name="phone"
                placeholder="Enter your phone number"
                value={user.phone}
                onChange={getuserData}
                autoComplete="off"
                required
              />
              <span className="focus-input100"></span>
            </div>
            <div className="wrap-input100rs1-wrap-input100">
              <span className="label-input100">Message</span>
              <textarea
                className="input100"
                name="message"
                placeholder="your message here..."
                value={user.message}
                onChange={getuserData}
              ></textarea>
              <span className="focus-input100"></span>
            </div>
            <div className="container-contact100-form-btn">
              <button className="contact100-form-btn" onClick={postData}>
                <span>
                  Submit
                  <i
                    className="fa fa-long-arrow-right m-l-7"
                    aria-hidden="true"
                  ></i>
                </span>
              </button>
            </div>
          </form>
          <span className="contact100-more">
            for any question contact our 24/7 call center:
            <span className="contact100-more-highlight">+91 7068633385</span>
          </span>
        </div>
      </div>
      <div className="footer">
        <h5>created by HIMANSHU GUPTA</h5>
      </div>
    </>
  );
};
export default Contact;
