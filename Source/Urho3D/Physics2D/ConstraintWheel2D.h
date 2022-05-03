//
// Copyright (c) 2008-2022 the Urho3D project.
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

#pragma once

#include "../Physics2D/Constraint2D.h"

namespace Urho3D
{

/// 2D wheel constraint component.
class URHO3D_API ConstraintWheel2D : public Constraint2D
{
    URHO3D_OBJECT(ConstraintWheel2D, Constraint2D);

public:
    /// Construct.
    explicit ConstraintWheel2D(Context* context);
    
    /// Destruct.
    ~ConstraintWheel2D() override;
    
    /// Register object factory.
    /// @nobind
    static void RegisterObject(Context* context);

    /// Set anchor.
    /// @property
    void SetAnchor(const Vector2& anchor);

    /// Return anchor.
    /// @property
    const Vector2& GetAnchor() const { return anchor_; }
    
    /// Set axis.
    /// @property
    void SetAxis(const Vector2& axis);

    /// Return axis.
    /// @property
    const Vector2& GetAxis() const { return axis_; }

    /// Set enable motor.
    /// @property
    void SetEnableMotor(bool enableMotor);

    /// Return enable motor.
    /// @property
    bool GetEnableMotor() const { return jointDef_.enableMotor; }

    /// Set max motor torque.
    /// @property
    void SetMaxMotorTorque(float maxMotorTorque);

    /// Return maxMotor torque.
    /// @property
    float GetMaxMotorTorque() const { return jointDef_.maxMotorTorque; }

    /// Set motor speed.
    /// @property
    void SetMotorSpeed(float motorSpeed);

    /// Return motor speed.
    /// @property
    float GetMotorSpeed() const { return jointDef_.motorSpeed; }

    /// Set linear stiffness in N/m.
    /// @property
    void SetStiffness(float stiffness);

    /// Return linear stiffness in N/m.
    /// @property
    float GetStiffness() const { return jointDef_.stiffness; }

    /// Set linear damping in N*s/m.
    /// @property
    void SetDamping(float damping);

    /// Return linear damping in N*s/m.
    /// @property
    float GetDamping() const { return jointDef_.damping; }

    /// Set enable limit.
    /// @property
    void SetEnableLimit(bool enableLimit);

    /// Return enable limit.
    /// @property
    bool GetEnableLimit()  const { return jointDef_.enableLimit; }

    /// Set lower translation.
    /// @property
    void SetLowerTranslation(float lowerTranslation);

    /// Return lower translation.
    /// @property
    float GetLowerTranslation() const { return jointDef_.lowerTranslation; }

    /// Set upper translation.
    /// @property
    void SetUpperTranslation(float upperTranslation);

    /// Return upper translation.
    /// @property
    float GetUpperTranslation() const { return jointDef_.upperTranslation; }

    /// Calc and set stiffness and damping. Must be used after set owner and other bodies.
    bool SetLinearStiffness(float frequencyHertz, float dampingRatio);

private:
    /// Return joint def.
    b2JointDef* GetJointDef() override;

    /// Box2D joint def.
    b2WheelJointDef jointDef_;
    
    /// Anchor.
    Vector2 anchor_;
    
    /// Axis.
    Vector2 axis_;
};

}