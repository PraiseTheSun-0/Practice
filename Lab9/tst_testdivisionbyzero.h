#ifndef TST_TESTDIVISIONBYZERO_H
#define TST_TESTDIVISIONBYZERO_H

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <IKeypad.h>
#include <ILatch.h>
#include <lockcontroller.h>

using namespace testing;

class mockKeypad : public IKeypad{
public:
    MOCK_METHOD(bool, isActive, (), (override));
    MOCK_METHOD(void, wait, (), (override));
    MOCK_METHOD(PasswordResponse, requestPassword, (), (override));
};

class mockLatch : public ILatch{
public:
    MOCK_METHOD(bool, isActive, (), (override));
    MOCK_METHOD(DoorStatus, open, (), (override));
    MOCK_METHOD(DoorStatus, close, (), (override));
    MOCK_METHOD(DoorStatus, getDoorStatus, (), (override));
};

class LockControllerTest : public Test
{
public:
    mockKeypad keypad;
    mockLatch latch;
    LockController* lock_contoller;

    static void SetUpTestSuite() {}
    static void TearDownTestSuite() {}
    void SetUp() override
    {
        lock_contoller = new LockController(&keypad, &latch);
    }
    void TearDown() override
    {
        delete lock_contoller;
    };
};

TEST_F(LockControllerTest, isWaiting){
    // Arrange
    EXPECT_CALL(keypad, wait())
            .Times(1)
            .WillOnce(Return());

    // Act
    lock_contoller->wait();

    // Assert


}

TEST_F(LockControllerTest, isClosedDoorOpen){
    // Arrange
    EXPECT_CALL(latch, getDoorStatus())
            .Times(1)
            .WillOnce(Return(DoorStatus::CLOSE));
    bool isOpen;

    // Act
    isOpen = lock_contoller->isDoorOpen();

    // Assert
    EXPECT_FALSE(isOpen);

}

TEST_F(LockControllerTest, isOpenDoorOpen){
    // Arrange
    EXPECT_CALL(latch, getDoorStatus())
            .Times(1)
            .WillOnce(Return(DoorStatus::OPEN));
    bool isOpen;

    // Act
    isOpen = lock_contoller->isDoorOpen();

    // Assert
    EXPECT_TRUE(isOpen);

}

TEST_F(LockControllerTest, isOpening){
    // Arrange
    EXPECT_CALL(latch, open())
            .Times(1)
            .WillOnce(Return(DoorStatus::OPEN));
    DoorStatus result;

    // Act
    result = lock_contoller->unlockDoor();

    // Assert
    EXPECT_EQ(result, DoorStatus::OPEN);

}

TEST_F(LockControllerTest, isClosing){
    // Arrange
    EXPECT_CALL(latch, close())
            .Times(1)
            .WillOnce(Return(DoorStatus::CLOSE));
    DoorStatus result;

    // Act
    result = lock_contoller->lockDoor();

    // Assert
    EXPECT_EQ(result, DoorStatus::CLOSE);

}

TEST_F(LockControllerTest, isHardWareWorking)
{
    // Arrange
    EXPECT_CALL(keypad, isActive())
            .Times(1)
            .WillOnce(Return(true));
    EXPECT_CALL(latch, isActive())
            .Times(1)
            .WillOnce(Return(true));
    HardWareStatus result;

    // Act
    result = lock_contoller->hardWareCheck();

    // Assert
    EXPECT_EQ(result, HardWareStatus::OK);
}

TEST_F(LockControllerTest, isHardWareNotWorking)
{
    // Arrange
    delete lock_contoller;

    lock_contoller = new LockController(nullptr, &latch);

    EXPECT_CALL(keypad, isActive())
            .Times(AtLeast(0))
            .WillOnce(Return(true));
    EXPECT_CALL(latch, isActive())
            .Times(AtLeast(0))
            .WillOnce(Return(true));
    HardWareStatus result;

    // Act
    result = lock_contoller->hardWareCheck();

    // Assert
    EXPECT_EQ(result, HardWareStatus::ERROR);
}

TEST_F(LockControllerTest, isLatchNotWorking)
{
    // Arrange
        EXPECT_CALL(keypad, isActive())
                .Times(AtLeast(0))
                .WillOnce(Return(true));
        EXPECT_CALL(latch, isActive())
                .Times(AtLeast(0))
                .WillOnce(Return(false));
        HardWareStatus result;

        // Act
        result = lock_contoller->hardWareCheck();

        // Assert
        EXPECT_EQ(result, HardWareStatus::ERROR);
}

TEST_F(LockControllerTest, isPasswordCorrect) {
    // Arrange
    PasswordResponse password;

    password.password = "0000";
    password.status = PasswordResponse::Status::OK;
    EXPECT_CALL(keypad, requestPassword())
            .Times(1)
            .WillOnce(Return(password));
    bool result;

    // Act
    result = lock_contoller->isCorrectPassword();

    // Assert
    EXPECT_TRUE(result);
}

TEST_F(LockControllerTest, isPasswordNotCorrect) {
    // Arrange
    PasswordResponse password;

    password.password = "1337";
    password.status = PasswordResponse::Status::OK;

    EXPECT_CALL(keypad, requestPassword())
            .Times(1)
            .WillOnce(Return(password));
    bool result;

    // Act
    result = lock_contoller->isCorrectPassword();

    // Assert
    EXPECT_FALSE(result);
}

TEST_F(LockControllerTest, isDefaultPasswordChanging)
{
    // Arrange
       PasswordResponse password1;
       password1.password = "0000";
       password1.status = PasswordResponse::Status::OK;

       PasswordResponse password2;
       password2.password = "1337";
       password2.status = PasswordResponse::Status::OK;

       PasswordResponse password3;
       password3.password = "1337";
       password3.status = PasswordResponse::Status::OK;

       EXPECT_CALL(keypad, requestPassword())
               .Times(3)
               .WillOnce(Return(password1))
               .WillOnce(Return(password2))
               .WillOnce(Return(password3));
       bool result;

       // Act
       lock_contoller->resetPassword();
       result = lock_contoller->isCorrectPassword();

       // Assert
       EXPECT_TRUE(result);
}

TEST_F(LockControllerTest, isPasswordChanging)
{
    // Arrange
        PasswordResponse password1;
        password1.password = "0000";
        password1.status = PasswordResponse::Status::OK;

        PasswordResponse password2;
        password2.password = "9876";
        password2.status = PasswordResponse::Status::OK;

        PasswordResponse password3;
        password3.password = "9876";
        password3.status = PasswordResponse::Status::OK;

        PasswordResponse password4;
        password4.password = "1337";
        password4.status = PasswordResponse::Status::OK;

        PasswordResponse password5;
        password5.password = "1337";
        password5.status = PasswordResponse::Status::OK;

        EXPECT_CALL(keypad, requestPassword())
                .Times(5)
                .WillOnce(Return(password1))
                .WillOnce(Return(password2))
                .WillOnce(Return(password3))
                .WillOnce(Return(password4))
                .WillOnce(Return(password5));
        bool result;

        // Act
        lock_contoller->resetPassword();
        lock_contoller->resetPassword();
        result = lock_contoller->isCorrectPassword();

        // Assert
        EXPECT_TRUE(result);
}



#endif // TST_TESTDIVISIONBYZERO_H
