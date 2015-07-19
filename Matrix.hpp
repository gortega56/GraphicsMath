//	Matrix.hpp
//	Gabriel Ortega
//
//	

#pragma once
#include "Vector.hpp"

#ifdef _WINDLL
#define CGM_DLL __declspec(dllexport)
#else
#define CGM_DLL __declspec(dllimport)
#endif

namespace cliqCity
{
	namespace graphicsMath
	{
		struct CGM_DLL Matrix2
		{
			Vector2 u, v;

			Matrix2(const Vector2& u, const Vector2& v);
			Matrix2(
				const float& u1, const float& u2,
				const float& v1, const float& v2);
			Matrix2(float m[2][2]);
			Matrix2(float s);
			Matrix2();

			Matrix2 transpose()		const;
			Matrix2 inverse()		const;
			float	determinant()	const;

			Matrix2& operator+=(const Matrix2& rhs);
			Matrix2& operator-=(const Matrix2& rhs);
			Matrix2& operator*=(const float& rhs);

			Matrix2& operator=(const Matrix2& rhs);
			Matrix2& operator-();

			Vector2& operator[](const unsigned int& index);
			float&	 operator()(const unsigned int& row, const unsigned int& column);
		};

		struct CGM_DLL Matrix3
		{
			Vector3 u, v, w;

			static Matrix3 scale(const Vector3& s);
			static Matrix3 rotate(const float& angle, const Vector3& a);
			static Matrix3 rotateX(const float& angle);
			static Matrix3 rotateY(const float& angle);
			static Matrix3 rotateZ(const float& angle);

			Matrix3(const Vector3& u, const Vector3& v, const Vector3& w);
			Matrix3(
				const float& u1, const float& u2, const float& u3,
				const float& v1, const float& v2, const float& v3,
				const float& w1, const float& w2, const float& w3);
			Matrix3(float m[3][3]);
			Matrix3(float s);
			Matrix3();

			Matrix3 transpose()		const;
			Matrix3 inverse()		const;
			float	determinant()	const;

			Matrix3& operator+=(const Matrix3& rhs);
			Matrix3& operator-=(const Matrix3& rhs);
			Matrix3& operator*=(const float& rhs);

			Matrix3& operator=(const Matrix3& rhs);
			Matrix3& operator-();

			Vector3& operator[](const unsigned int& index);
			float&	 operator()(const unsigned int& row, const unsigned int& column);
		};

		struct CGM_DLL Matrix4
		{
			Vector4 u, v, w, t;

			static Matrix4 orthographic(const float& left, const float& right, const float& bottom, const float& top, const float& zNear, const float& zFar);
			static Matrix4 perspective(const float& fovy, const float& aspectRatio, const float& zNear, const float& zFar);
			static Matrix4 frustum(const float& left, const float& right, const float& bottom, const float& top, const float& zNear, const float& zFar);

			static Matrix4 lookTo(const Vector3& direction, const Vector3& position, const Vector3& up);
			static Matrix4 lookAt(const Vector3& target, const Vector3& position, const Vector3& up);

			static Matrix4 scale(const Vector3& s);

			static Matrix4 rotate(const float& angle, const Vector3& a);
			static Matrix4 rotateX(const float& angle);
			static Matrix4 rotateY(const float& angle);
			static Matrix4 rotateZ(const float& angle);

			static Matrix4 translate(const Vector3& t);

			Matrix4(const Vector4& u, const Vector4& v, const Vector4& w, const Vector4& t);
			Matrix4(
				const float& u1, const float& u2, const float& u3, const float& u4,
				const float& v1, const float& v2, const float& v3, const float& v4,
				const float& w1, const float& w2, const float& w3, const float& w4,
				const float& t1, const float& t2, const float& t3, const float& t4);
			Matrix4(float m[4][4]);
			Matrix4(float s);
			Matrix4();

			Matrix4 transpose()		const;
			Matrix4 inverse()		const;
			float	determinant()	const;

			Matrix4 operator+=(const Matrix4& rhs);
			Matrix4 operator-=(const Matrix4& rhs);
			Matrix4 operator*=(const float& rhs);

			Matrix4 operator=(const Matrix4& rhs);
			Matrix4 operator-();

			Vector4& operator[](const unsigned int& index);
			float&	 operator()(const unsigned int& row, const unsigned int& column);

			operator Matrix3();
		};

		// Binary (Matrix2)

		CGM_DLL Matrix2 operator+(const Matrix2& lhs, const Matrix2& rhs);
		CGM_DLL Matrix2 operator-(const Matrix2& lhs, const Matrix2& rhs);
		CGM_DLL Matrix2 operator*(const Matrix2& lhs, const Matrix2& rhs);
		CGM_DLL Matrix2 operator*(const Matrix2& lhs, const float& rhs);
		CGM_DLL Matrix2 operator*(const float& lhs, const Matrix2& rhs);
		CGM_DLL Vector2 operator*(const Vector2& lhs, const Matrix2& rhs);

		// Binary (Matrix3)

		CGM_DLL Matrix3 operator+(const Matrix3& lhs, const Matrix3& rhs);
		CGM_DLL Matrix3 operator-(const Matrix3& lhs, const Matrix3& rhs);
		CGM_DLL Matrix3 operator*(const Matrix3& lhs, const Matrix3& rhs);
		CGM_DLL Matrix3 operator*(const Matrix3& lhs, const float& rhs);
		CGM_DLL Matrix3 operator*(const float& lhs, const Matrix3& rhs);
		CGM_DLL Vector3 operator*(const Vector3& lhs, const Matrix3& rhs);

		// Binary (Matrix4)

		CGM_DLL Matrix4 operator+(const Matrix4& lhs, const Matrix4& rhs);
		CGM_DLL Matrix4 operator-(const Matrix4& lhs, const Matrix4& rhs);
		CGM_DLL Matrix4 operator*(const Matrix4& lhs, const Matrix4& rhs);
		CGM_DLL Matrix4 operator*(const Matrix4& lhs, const float& rhs);
		CGM_DLL Matrix4 operator*(const float& lhs, const Matrix4& rhs);
		CGM_DLL Vector4 operator*(const Vector4& lhs, const Matrix4& rhs);
	}
}