static void
tmat3x4_dealloc(tmat3x4* self)
{
	Py_DECREF(self->x);
	Py_DECREF(self->y);
	Py_DECREF(self->z);
	//Py_DECREF(self->col_type);
	//Py_DECREF(self->row_type);
	Py_TYPE(self)->tp_free((PyObject*)self);
}

static PyObject *
tmat3x4_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
	tmat3x4 *self;

	self = (tmat3x4 *)type->tp_alloc(type, 0);

	PyObject *v1 = pack_tvec4(0, 0, 0, 0);
	PyObject *v2 = pack_tvec4(0, 0, 0, 0);
	PyObject *v3 = pack_tvec4(0, 0, 0, 0);

	if (self != NULL) {
		self->x = (tvec4*)v1;
		self->y = (tvec4*)v2;
		self->z = (tvec4*)v3;
		self->col_type = (PyObject*)&tvec4Type;
		self->row_type = (PyObject*)&tvec4Type;
	}

	return (PyObject *)self;
}

static int
tmat3x4_init(tmat3x4 *self, PyObject *args, PyObject *kwds)
{
	static char *kwlist[] = { "x0", "x1", "x2", "x3", "y0", "y1", "y2", "y3", "z0", "z1", "z2", "z3", NULL };

	PyObject *arg1 = NULL;
	PyObject *arg2 = NULL;
	PyObject *arg3 = NULL;
	PyObject *arg4 = NULL;
	PyObject *arg5 = NULL;
	PyObject *arg6 = NULL;
	PyObject *arg7 = NULL;
	PyObject *arg8 = NULL;
	PyObject *arg9 = NULL;
	PyObject *arg10 = NULL;
	PyObject *arg11 = NULL;
	PyObject *arg12 = NULL;

	if (!PyArg_ParseTupleAndKeywords(args, kwds, "|OOOOOOOOOOOO", kwlist,
		&arg1, &arg2, &arg3, &arg4, &arg5, &arg6, &arg7, &arg8, &arg9, &arg10, &arg11, &arg12)) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for tmat3x4()");
		return -1;
	}

	if (arg1 == NULL) {
		return 0;
	}

	if (arg2 == NULL) {
		if (IS_NUMERIC(arg1)) {
			self->x->x = self->y->y = self->z->z = pyvalue_as_double(arg1);
			return 0;
		}
		void* o = NULL;
		char vecType = unpack_imat(arg1, &o);
		switch (vecType) {
		case GLM_TMAT2x2:
			self->x->x = ((imat2x2*)o)->x.x;
			self->x->y = ((imat2x2*)o)->x.y;
			self->x->z = 0.0;
			self->x->w = 0.0;
			self->y->x = ((imat2x2*)o)->y.x;
			self->y->y = ((imat2x2*)o)->y.y;
			self->y->z = 0.0;
			self->y->w = 0.0;
			self->z->x = 0.0;
			self->z->y = 0.0;
			self->z->z = 1.0;
			self->z->w = 0.0;
			free(o);
			return 0;
		case GLM_TMAT2x3:
			self->x->x = ((imat2x3*)o)->x.x;
			self->x->y = ((imat2x3*)o)->x.y;
			self->x->z = ((imat2x3*)o)->x.z;
			self->x->w = 0.0;
			self->y->x = ((imat2x3*)o)->y.x;
			self->y->y = ((imat2x3*)o)->y.y;
			self->y->z = ((imat2x3*)o)->y.z;
			self->y->w = 0.0;
			self->z->x = 0.0;
			self->z->y = 0.0;
			self->z->z = 1.0;
			self->z->w = 0.0;
			free(o);
			return 0;
		case GLM_TMAT2x4:
			self->x->x = ((imat2x4*)o)->x.x;
			self->x->y = ((imat2x4*)o)->x.y;
			self->x->z = ((imat2x4*)o)->x.z;
			self->x->w = ((imat2x4*)o)->x.w;
			self->y->x = ((imat2x4*)o)->y.x;
			self->y->y = ((imat2x4*)o)->y.y;
			self->y->z = ((imat2x4*)o)->y.z;
			self->y->w = ((imat2x4*)o)->y.w;
			self->z->x = 0.0;
			self->z->y = 0.0;
			self->z->z = 1.0;
			self->z->w = 0.0;
			free(o);
			return 0;
		case GLM_TMAT3x2:
			self->x->x = ((imat3x2*)o)->x.x;
			self->x->y = ((imat3x2*)o)->x.y;
			self->x->z = 0.0;
			self->x->w = 0.0;
			self->y->x = ((imat3x2*)o)->y.x;
			self->y->y = ((imat3x2*)o)->y.y;
			self->y->z = 0.0;
			self->y->w = 0.0;
			self->z->x = ((imat3x2*)o)->z.x;
			self->z->y = ((imat3x2*)o)->z.y;
			self->z->z = 1.0;
			self->z->w = 0.0;
			free(o);
			return 0;
		case GLM_TMAT3x3:
			self->x->x = ((imat3x3*)o)->x.x;
			self->x->y = ((imat3x3*)o)->x.y;
			self->x->z = ((imat3x3*)o)->x.z;
			self->x->w = 0.0;
			self->y->x = ((imat3x3*)o)->y.x;
			self->y->y = ((imat3x3*)o)->y.y;
			self->y->z = ((imat3x3*)o)->y.z;
			self->y->w = 0.0;
			self->z->x = ((imat3x3*)o)->z.x;
			self->z->y = ((imat3x3*)o)->z.y;
			self->z->z = ((imat3x3*)o)->z.z;
			self->z->w = 0.0;
			free(o);
			return 0;
		case GLM_TMAT3x4:
			self->x->x = ((imat3x4*)o)->x.x;
			self->x->y = ((imat3x4*)o)->x.y;
			self->x->z = ((imat3x4*)o)->x.z;
			self->x->w = ((imat3x4*)o)->x.w;
			self->y->x = ((imat3x4*)o)->y.x;
			self->y->y = ((imat3x4*)o)->y.y;
			self->y->z = ((imat3x4*)o)->y.z;
			self->y->w = ((imat3x4*)o)->y.w;
			self->z->x = ((imat3x4*)o)->z.x;
			self->z->y = ((imat3x4*)o)->z.y;
			self->z->z = ((imat3x4*)o)->z.z;
			self->z->w = ((imat3x4*)o)->z.w;
			free(o);
			return 0;
		case GLM_TMAT4x2:
			self->x->x = ((imat4x2*)o)->x.x;
			self->x->y = ((imat4x2*)o)->x.y;
			self->x->z = 0.0;
			self->x->w = 0.0;
			self->y->x = ((imat4x2*)o)->y.x;
			self->y->y = ((imat4x2*)o)->y.y;
			self->y->z = 0.0;
			self->y->w = 0.0;
			self->z->x = ((imat4x2*)o)->z.x;
			self->z->y = ((imat4x2*)o)->z.y;
			self->z->z = 1.0;
			self->z->w = 0.0;
			free(o);
			return 0;
		case GLM_TMAT4x3:
			self->x->x = ((imat4x3*)o)->x.x;
			self->x->y = ((imat4x3*)o)->x.y;
			self->x->z = ((imat4x3*)o)->x.z;
			self->x->w = 0.0;
			self->y->x = ((imat4x3*)o)->y.x;
			self->y->y = ((imat4x3*)o)->y.y;
			self->y->z = ((imat4x3*)o)->y.z;
			self->y->w = 0.0;
			self->z->x = ((imat4x3*)o)->z.x;
			self->z->y = ((imat4x3*)o)->z.y;
			self->z->z = ((imat4x3*)o)->z.z;
			self->z->w = 0.0;
			free(o);
			return 0;
		case GLM_TMAT4x4:
			self->x->x = ((imat4x4*)o)->x.x;
			self->x->y = ((imat4x4*)o)->x.y;
			self->x->z = ((imat4x4*)o)->x.z;
			self->x->w = ((imat4x4*)o)->x.w;
			self->y->x = ((imat4x4*)o)->y.x;
			self->y->y = ((imat4x4*)o)->y.y;
			self->y->z = ((imat4x4*)o)->y.z;
			self->y->w = ((imat4x4*)o)->y.w;
			self->z->x = ((imat4x4*)o)->z.x;
			self->z->y = ((imat4x4*)o)->z.y;
			self->z->z = ((imat4x4*)o)->z.z;
			self->z->w = ((imat4x4*)o)->z.w;
			free(o);
			return 0;
		default:
			free(o);
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for tmat3x4()");
			return -1;
		}
	}
	if (arg3 == NULL) {
		return 0;
	}

	if (arg4 == NULL) {
		ivec4* o = unpack_ivec4(arg1);
		if (o == NULL) {
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for tmat3x4()");
			return -1;
		}
		ivec4* o2 = unpack_ivec4(arg2);
		if (o2 == NULL) {
			free(o);
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for tmat3x4()");
			return -1;
		}
		ivec4* o3 = unpack_ivec4(arg3);
		if (o3 == NULL) {
			free(o);
			free(o2);
			PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for tmat3x4()");
			return -1;
		}
		self->x->x = o->x;
		self->x->y = o->y;
		self->x->z = o->z;
		self->x->w = o->w;
		self->y->x = o2->x;
		self->y->y = o2->y;
		self->y->z = o2->z;
		self->y->w = o2->w;
		self->z->x = o3->x;
		self->z->y = o3->y;
		self->z->z = o3->z;
		self->z->w = o3->w;
		free(o);
		free(o2);
		free(o3);
		return 0;
	}

	if (arg5 == NULL || arg6 == NULL || arg7 == NULL || arg8 == NULL || arg9 == NULL || arg10 == NULL || arg11 == NULL || arg12 == NULL) {
		PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for tmat3x4()");
		return -1;
	}

	if (IS_NUMERIC(arg1) && IS_NUMERIC(arg2) && IS_NUMERIC(arg3) && IS_NUMERIC(arg4) && IS_NUMERIC(arg5) && IS_NUMERIC(arg6) && IS_NUMERIC(arg7) && IS_NUMERIC(arg8) && IS_NUMERIC(arg9) && IS_NUMERIC(arg10) && IS_NUMERIC(arg11) && IS_NUMERIC(arg12)) {
		self->x->x = pyvalue_as_double(arg1);
		self->x->y = pyvalue_as_double(arg2);
		self->x->z = pyvalue_as_double(arg3);
		self->x->w = pyvalue_as_double(arg4);
		self->y->x = pyvalue_as_double(arg5);
		self->y->y = pyvalue_as_double(arg6);
		self->y->z = pyvalue_as_double(arg7);
		self->y->w = pyvalue_as_double(arg8);
		self->z->x = pyvalue_as_double(arg9);
		self->z->y = pyvalue_as_double(arg10);
		self->z->z = pyvalue_as_double(arg11);
		self->z->w = pyvalue_as_double(arg12);
		return 0;
	}
	PyErr_SetString(PyExc_TypeError, "invalid argument type(s) for tmat3x4()");
	return -1;
}

// unaryfunc
static PyObject *
tmat3x4_neg(tmat3x4 *obj)
{
	PyObject* argList = Py_BuildValue("OOO", PyObject_CallMethod((PyObject*)obj->x, "__neg__", "()"), PyObject_CallMethod((PyObject*)obj->y, "__neg__", "()"), PyObject_CallMethod((PyObject*)obj->z, "__neg__", "()"));

	/* Call the class object. */
	PyObject *obj_out = PyObject_CallObject((PyObject *)&tmat3x4Type, argList);

	/* Release the argument list. */
	Py_DECREF(argList);

	return obj_out;
}

static PyObject *
tmat3x4_pos(tmat3x4 *obj)
{
	PyObject* argList = Py_BuildValue("OOO", obj->x, obj->y, obj->z);

	/* Call the class object. */
	PyObject *obj_out = PyObject_CallObject((PyObject *)&tmat3x4Type, argList);

	/* Release the argument list. */
	Py_DECREF(argList);

	return obj_out;
}

static PyObject *
tmat3x4_abs(tmat3x4 *obj)
{
	PyObject* argList = Py_BuildValue("OOO", PyObject_CallMethod((PyObject*)obj->x, "__abs__", "()"), PyObject_CallMethod((PyObject*)obj->y, "__abs__", "()"), PyObject_CallMethod((PyObject*)obj->z, "__abs__", "()"));

	/* Call the class object. */
	PyObject *obj_out = PyObject_CallObject((PyObject *)&tmat3x4Type, argList);

	/* Release the argument list. */
	Py_DECREF(argList);

	return obj_out;
}

// binaryfunc
static PyObject *
tmat3x4_add(PyObject *obj1, PyObject *obj2)
{
	imat3x4 o;

	if (IS_NUMERIC(obj1)) { // obj1 is a scalar
		o.x.x = o.x.y = o.x.z = o.x.w = o.y.x = o.y.y = o.y.z = o.y.w = o.z.x = o.z.y = o.z.z = o.z.w = pyvalue_as_double(obj1);
	}
	else { // obj1 can be converted to a tmat3x4
		if (!unpack_imat3x4p(obj1, &o)) { // obj1 can't be interpreted as tmat3x4
			PyErr_SetString(PyExc_TypeError, "unsupported operand type(s) for + of 'glm::detail::tmat3x4'");
			return NULL;
		}
	}

	if (IS_NUMERIC(obj2)) { // obj2 is a scalar
		double d = pyvalue_as_double(obj2);
		o.x.x += d;
		o.x.y += d;
		o.x.z += d;
		o.x.w += d;
		o.y.x += d;
		o.y.y += d;
		o.y.z += d;
		o.y.w += d;
		o.z.x += d;
		o.z.y += d;
		o.z.z += d;
		o.z.w += d;
	}
	else { // obj2 can be converted to a tmat3x4
		imat3x4 o2;

		if (!unpack_imat3x4p(obj2, &o2)) { // obj2 can't be interpreted as tmat3x4
			PyObject * out = PyObject_CallMethod(obj2, "__radd__", "O", obj1);
			if (out == NULL) {
				PY_TYPEERROR("unsupported operand type(s) for +: 'glm::detail::tmat3x4' and ", obj2);
				return NULL;
			}
			return out;
		}

		o.x.x += o2.x.x;
		o.x.y += o2.x.y;
		o.x.z += o2.x.z;
		o.x.w += o2.x.w;
		o.y.x += o2.y.x;
		o.y.y += o2.y.y;
		o.y.z += o2.y.z;
		o.y.w += o2.y.w;
		o.z.x += o2.z.x;
		o.z.y += o2.z.y;
		o.z.z += o2.z.z;
		o.z.w += o2.z.w;
	}

	return build_imat3x4(o);
}

static PyObject *
tmat3x4_sub(PyObject *obj1, PyObject *obj2)
{
	imat3x4 o;

	if (IS_NUMERIC(obj1)) { // obj1 is a scalar
		o.x.x = o.x.y = o.x.z = o.x.w = o.y.x = o.y.y = o.y.z = o.y.w = o.z.x = o.z.y = o.z.z = o.z.w = pyvalue_as_double(obj1);
	}
	else { // obj1 can be converted to a tmat3x4
		if (!unpack_imat3x4p(obj1, &o)) { // obj1 can't be interpreted as tmat3x4
			PY_TYPEERROR_2O("unsupported operand type(s) for -: ", obj1, obj2);
			return NULL;
		}
	}

	if (IS_NUMERIC(obj2)) { // obj2 is a scalar
		double d = pyvalue_as_double(obj2);
		o.x.x -= d;
		o.x.y -= d;
		o.x.z -= d;
		o.x.w -= d;
		o.y.x -= d;
		o.y.y -= d;
		o.y.z -= d;
		o.y.w -= d;
		o.z.x -= d;
		o.z.y -= d;
		o.z.z -= d;
		o.z.w -= d;
	}
	else { // obj2 can be converted to a tmat3x4
		imat3x4 o2;

		if (!unpack_imat3x4p(obj2, &o2)) { // obj2 can't be interpreted as tmat3x4
			PyObject * out = PyObject_CallMethod(obj2, "__rsub__", "O", obj1);
			if (out == NULL) {
				PY_TYPEERROR("unsupported operand type(s) for -: 'glm::detail::tmat3x4' and ", obj2);
				return NULL;
			}
			return out;
		}

		o.x.x -= o2.x.x;
		o.x.y -= o2.x.y;
		o.x.z -= o2.x.z;
		o.x.w -= o2.x.w;
		o.y.x -= o2.y.x;
		o.y.y -= o2.y.y;
		o.y.z -= o2.y.z;
		o.y.w -= o2.y.w;
		o.z.x -= o2.z.x;
		o.z.y -= o2.z.y;
		o.z.z -= o2.z.z;
		o.z.w -= o2.z.w;
	}

	return build_imat3x4(o);
}

static PyObject *
tmat3x4_mul(PyObject *obj1, PyObject *obj2)
{
	if (IS_NUMERIC(obj1)) { // obj1 is a scalar
		double d = pyvalue_as_double(obj1);

		imat3x4* o2 = unpack_imat3x4(obj2);

		if (o2 == NULL) { // obj2 can't be interpreted as tmat3x4
			PY_TYPEERROR("unsupported operand type(s) for *: 'glm::detail::tmat3x4' and ", obj2);
			return NULL;
		}

		PyObject* out = pack_tmat3x4(
			d * o2->x.x,
			d * o2->x.y,
			d * o2->x.z,
			d * o2->x.w,
			d * o2->y.x,
			d * o2->y.y,
			d * o2->y.z,
			d * o2->y.w,
			d * o2->z.x,
			d * o2->z.y,
			d * o2->z.z,
			d * o2->z.w);
		free(o2);
		return out;
	}

	void* o = NULL;
	char glmType = unpack_pyobject(obj1, &o, GLM_HAS_TVEC4 | GLM_HAS_TMAT3x4);

	if (glmType == GLM_TVEC4) { // obj1 is a col_type
		imat3x4* o2 = unpack_imat3x4(obj2);

		if (o2 == NULL) { // obj2 can't be interpreted as tmat3x4
			free(o);
			PY_TYPEERROR("unsupported operand type(s) for *: 'glm::detail::tmat3x4' and ", obj2);
			return NULL;
		}

		PyObject* out = pack_tvec3(
			((ivec4*)o)->x * o2->x.x + ((ivec4*)o)->y * o2->x.y + ((ivec4*)o)->z * o2->x.z + ((ivec4*)o)->w * o2->x.w,
			((ivec4*)o)->x * o2->y.x + ((ivec4*)o)->y * o2->y.y + ((ivec4*)o)->z * o2->y.z + ((ivec4*)o)->w * o2->y.w,
			((ivec4*)o)->x * o2->z.x + ((ivec4*)o)->y * o2->z.y + ((ivec4*)o)->z * o2->z.z + ((ivec4*)o)->w * o2->z.w);
		free(o);
		free(o2);
		return out;
	}

	if (glmType != GLM_TMAT3x4) { // obj1 can't be interpreted as tmat3x4
		free(o);
		PY_TYPEERROR_2O("unsupported operand type(s) for *: ", obj1, obj2);
		return NULL;
	}

	if (IS_NUMERIC(obj2)) { // obj2 is a scalar
		double d = pyvalue_as_double(obj2);
		((imat3x4*)o)->x.x *= d;
		((imat3x4*)o)->x.y *= d;
		((imat3x4*)o)->x.z *= d;
		((imat3x4*)o)->x.w *= d;
		((imat3x4*)o)->y.x *= d;
		((imat3x4*)o)->y.y *= d;
		((imat3x4*)o)->y.z *= d;
		((imat3x4*)o)->y.w *= d;
		((imat3x4*)o)->z.x *= d;
		((imat3x4*)o)->z.y *= d;
		((imat3x4*)o)->z.z *= d;
		((imat3x4*)o)->z.w *= d;
		PyObject* out = build_imat3x4p(o);
		free(o);
		return out;
	}

	void* o2 = NULL;
	glmType = unpack_pyobject(obj2, &o2, GLM_HAS_TVEC3 | GLM_HAS_TMAT2x3 | GLM_HAS_TMAT3x3 | GLM_HAS_TMAT4x3);

	if (glmType == GLM_TVEC3) { // obj2 is a row_type
		PyObject* out = pack_tvec4(
			((imat3x4*)o)->x.x * ((ivec4*)o2)->x + ((imat3x4*)o)->y.x * ((ivec4*)o2)->y + ((imat3x4*)o)->z.x * ((ivec4*)o2)->z,
			((imat3x4*)o)->x.y * ((ivec4*)o2)->x + ((imat3x4*)o)->y.y * ((ivec4*)o2)->y + ((imat3x4*)o)->z.y * ((ivec4*)o2)->z,
			((imat3x4*)o)->x.z * ((ivec4*)o2)->x + ((imat3x4*)o)->y.z * ((ivec4*)o2)->y + ((imat3x4*)o)->z.z * ((ivec4*)o2)->z,
			((imat3x4*)o)->x.w * ((ivec4*)o2)->x + ((imat3x4*)o)->y.w * ((ivec4*)o2)->y + ((imat3x4*)o)->z.w * ((ivec4*)o2)->z);
		free(o);
		free(o2);
		return out;
	}

	if (glmType == GLM_TMAT2x3) { // obj2 is a tmat2x3
		PyObject* out = pack_tmat2x4(
			((imat3x4*)o)->x.x * ((imat2x3*)o2)->x.x + ((imat3x4*)o)->y.x * ((imat2x3*)o2)->x.y + ((imat3x4*)o)->z.x * ((imat2x3*)o2)->x.z,
			((imat3x4*)o)->x.y * ((imat2x3*)o2)->x.x + ((imat3x4*)o)->y.y * ((imat2x3*)o2)->x.y + ((imat3x4*)o)->z.y * ((imat2x3*)o2)->x.z,
			((imat3x4*)o)->x.z * ((imat2x3*)o2)->x.x + ((imat3x4*)o)->y.z * ((imat2x3*)o2)->x.y + ((imat3x4*)o)->z.z * ((imat2x3*)o2)->x.z,
			((imat3x4*)o)->x.w * ((imat2x3*)o2)->x.x + ((imat3x4*)o)->y.w * ((imat2x3*)o2)->x.y + ((imat3x4*)o)->z.w * ((imat2x3*)o2)->x.z,
			((imat3x4*)o)->x.x * ((imat2x3*)o2)->y.x + ((imat3x4*)o)->y.x * ((imat2x3*)o2)->y.y + ((imat3x4*)o)->z.x * ((imat2x3*)o2)->y.z,
			((imat3x4*)o)->x.y * ((imat2x3*)o2)->y.x + ((imat3x4*)o)->y.y * ((imat2x3*)o2)->y.y + ((imat3x4*)o)->z.y * ((imat2x3*)o2)->y.z,
			((imat3x4*)o)->x.z * ((imat2x3*)o2)->y.x + ((imat3x4*)o)->y.z * ((imat2x3*)o2)->y.y + ((imat3x4*)o)->z.z * ((imat2x3*)o2)->y.z,
			((imat3x4*)o)->x.w * ((imat2x3*)o2)->y.x + ((imat3x4*)o)->y.w * ((imat2x3*)o2)->y.y + ((imat3x4*)o)->z.w * ((imat2x3*)o2)->y.z);
		free(o);
		free(o2);
		return out;
	}

	if (glmType == GLM_TMAT3x3) {// obj2 is a tmat3x4
		PyObject* out = pack_tmat3x4(
			((imat3x4*)o)->x.x * ((imat3x3*)o2)->x.x + ((imat3x4*)o)->y.x * ((imat3x3*)o2)->x.y + ((imat3x4*)o)->z.x * ((imat3x3*)o2)->x.z,
			((imat3x4*)o)->x.y * ((imat3x3*)o2)->x.x + ((imat3x4*)o)->y.y * ((imat3x3*)o2)->x.y + ((imat3x4*)o)->z.y * ((imat3x3*)o2)->x.z,
			((imat3x4*)o)->x.z * ((imat3x3*)o2)->x.x + ((imat3x4*)o)->y.z * ((imat3x3*)o2)->x.y + ((imat3x4*)o)->z.z * ((imat3x3*)o2)->x.z,
			((imat3x4*)o)->x.w * ((imat3x3*)o2)->x.x + ((imat3x4*)o)->y.w * ((imat3x3*)o2)->x.y + ((imat3x4*)o)->z.w * ((imat3x3*)o2)->x.z,
			((imat3x4*)o)->x.x * ((imat3x3*)o2)->y.x + ((imat3x4*)o)->y.x * ((imat3x3*)o2)->y.y + ((imat3x4*)o)->z.x * ((imat3x3*)o2)->y.z,
			((imat3x4*)o)->x.y * ((imat3x3*)o2)->y.x + ((imat3x4*)o)->y.y * ((imat3x3*)o2)->y.y + ((imat3x4*)o)->z.y * ((imat3x3*)o2)->y.z,
			((imat3x4*)o)->x.z * ((imat3x3*)o2)->y.x + ((imat3x4*)o)->y.z * ((imat3x3*)o2)->y.y + ((imat3x4*)o)->z.z * ((imat3x3*)o2)->y.z,
			((imat3x4*)o)->x.w * ((imat3x3*)o2)->y.x + ((imat3x4*)o)->y.w * ((imat3x3*)o2)->y.y + ((imat3x4*)o)->z.w * ((imat3x3*)o2)->y.z,
			((imat3x4*)o)->x.x * ((imat3x3*)o2)->z.x + ((imat3x4*)o)->y.x * ((imat3x3*)o2)->z.y + ((imat3x4*)o)->z.x * ((imat3x3*)o2)->z.z,
			((imat3x4*)o)->x.y * ((imat3x3*)o2)->z.x + ((imat3x4*)o)->y.y * ((imat3x3*)o2)->z.y + ((imat3x4*)o)->z.y * ((imat3x3*)o2)->z.z,
			((imat3x4*)o)->x.z * ((imat3x3*)o2)->z.x + ((imat3x4*)o)->y.z * ((imat3x3*)o2)->z.y + ((imat3x4*)o)->z.z * ((imat3x3*)o2)->z.z,
			((imat3x4*)o)->x.w * ((imat3x3*)o2)->z.x + ((imat3x4*)o)->y.w * ((imat3x3*)o2)->z.y + ((imat3x4*)o)->z.w * ((imat3x3*)o2)->z.z);
		free(o);
		free(o2);
		return out;
	}

	if (glmType == GLM_TMAT4x3) { // obj2 is a tmat4x3
		PyObject* out = pack_tmat4x4(
			((imat3x4*)o)->x.x * ((imat4x3*)o2)->x.x + ((imat3x4*)o)->y.x * ((imat4x3*)o2)->x.y + ((imat3x4*)o)->z.x * ((imat4x3*)o2)->x.z,
			((imat3x4*)o)->x.y * ((imat4x3*)o2)->x.x + ((imat3x4*)o)->y.y * ((imat4x3*)o2)->x.y + ((imat3x4*)o)->z.y * ((imat4x3*)o2)->x.z,
			((imat3x4*)o)->x.z * ((imat4x3*)o2)->x.x + ((imat3x4*)o)->y.z * ((imat4x3*)o2)->x.y + ((imat3x4*)o)->z.z * ((imat4x3*)o2)->x.z,
			((imat3x4*)o)->x.w * ((imat4x3*)o2)->x.x + ((imat3x4*)o)->y.w * ((imat4x3*)o2)->x.y + ((imat3x4*)o)->z.w * ((imat4x3*)o2)->x.z,
			((imat3x4*)o)->x.x * ((imat4x3*)o2)->y.x + ((imat3x4*)o)->y.x * ((imat4x3*)o2)->y.y + ((imat3x4*)o)->z.x * ((imat4x3*)o2)->y.z,
			((imat3x4*)o)->x.y * ((imat4x3*)o2)->y.x + ((imat3x4*)o)->y.y * ((imat4x3*)o2)->y.y + ((imat3x4*)o)->z.y * ((imat4x3*)o2)->y.z,
			((imat3x4*)o)->x.z * ((imat4x3*)o2)->y.x + ((imat3x4*)o)->y.z * ((imat4x3*)o2)->y.y + ((imat3x4*)o)->z.z * ((imat4x3*)o2)->y.z,
			((imat3x4*)o)->x.w * ((imat4x3*)o2)->y.x + ((imat3x4*)o)->y.w * ((imat4x3*)o2)->y.y + ((imat3x4*)o)->z.w * ((imat4x3*)o2)->y.z,
			((imat3x4*)o)->x.x * ((imat4x3*)o2)->z.x + ((imat3x4*)o)->y.x * ((imat4x3*)o2)->z.y + ((imat3x4*)o)->z.x * ((imat4x3*)o2)->z.z,
			((imat3x4*)o)->x.y * ((imat4x3*)o2)->z.x + ((imat3x4*)o)->y.y * ((imat4x3*)o2)->z.y + ((imat3x4*)o)->z.y * ((imat4x3*)o2)->z.z,
			((imat3x4*)o)->x.z * ((imat4x3*)o2)->z.x + ((imat3x4*)o)->y.z * ((imat4x3*)o2)->z.y + ((imat3x4*)o)->z.z * ((imat4x3*)o2)->z.z,
			((imat3x4*)o)->x.w * ((imat4x3*)o2)->z.x + ((imat3x4*)o)->y.w * ((imat4x3*)o2)->z.y + ((imat3x4*)o)->z.w * ((imat4x3*)o2)->z.z,
			((imat3x4*)o)->x.x * ((imat4x3*)o2)->w.x + ((imat3x4*)o)->y.x * ((imat4x3*)o2)->w.y + ((imat3x4*)o)->z.x * ((imat4x3*)o2)->w.z,
			((imat3x4*)o)->x.y * ((imat4x3*)o2)->w.x + ((imat3x4*)o)->y.y * ((imat4x3*)o2)->w.y + ((imat3x4*)o)->z.y * ((imat4x3*)o2)->w.z,
			((imat3x4*)o)->x.z * ((imat4x3*)o2)->w.x + ((imat3x4*)o)->y.z * ((imat4x3*)o2)->w.y + ((imat3x4*)o)->z.z * ((imat4x3*)o2)->w.z,
			((imat3x4*)o)->x.w * ((imat4x3*)o2)->w.x + ((imat3x4*)o)->y.w * ((imat4x3*)o2)->w.y + ((imat3x4*)o)->z.w * ((imat4x3*)o2)->w.z);
		free(o);
		free(o2);
		return out;
	}
	free(o);
	free(o2);
	PyObject * out = PyObject_CallMethod(obj2, "__rmul__", "O", obj1);
	if (out == NULL) {
		PY_TYPEERROR("unsupported operand type(s) for *: 'glm::detail::tmat3x4' and ", obj2);
		return NULL;
	}
	return out;
}

static PyObject *
tmat3x4_div(PyObject *obj1, PyObject *obj2)
{
	if (IS_NUMERIC(obj1)) { // obj1 is a scalar
		double d = pyvalue_as_double(obj1);

		imat3x4* o2 = unpack_imat3x4(obj2);

		if (o2 == NULL) { // obj2 can't be interpreted as tmat3x4
			PY_TYPEERROR("unsupported operand type(s) for /: 'glm::detail::tmat3x4' and ", obj2);
			return NULL;
		}

		PyObject* out = pack_tmat3x4(
			d / o2->x.x,
			d / o2->x.y,
			d / o2->x.z,
			d / o2->x.w,
			d / o2->y.x,
			d / o2->y.y,
			d / o2->y.z,
			d / o2->y.w,
			d / o2->z.x,
			d / o2->z.y,
			d / o2->z.z,
			d / o2->z.w);
		free(o2);
		return out;
	}

	imat3x4* o = unpack_imat3x4(obj1);

	if (o == NULL) { // obj1 can't be interpreted as tmat3x4
		PY_TYPEERROR_2O("unsupported operand type(s) for /: ", obj1, obj2);
		return NULL;
	}

	if (IS_NUMERIC(obj2)) { // obj2 is a scalar
		double d = pyvalue_as_double(obj2);
		((imat3x4*)o)->x.x /= d;
		((imat3x4*)o)->x.y /= d;
		((imat3x4*)o)->x.z /= d;
		((imat3x4*)o)->x.w /= d;
		((imat3x4*)o)->y.x /= d;
		((imat3x4*)o)->y.y /= d;
		((imat3x4*)o)->y.z /= d;
		((imat3x4*)o)->y.w /= d;
		((imat3x4*)o)->z.x /= d;
		((imat3x4*)o)->z.y /= d;
		((imat3x4*)o)->z.z /= d;
		((imat3x4*)o)->z.w /= d;
		PyObject* out = build_imat3x4p(o);
		free(o);
		return out;
	}
	free(o);
	PyObject * out = PyObject_CallMethod(obj2, "__rtruediv__", "O", obj1);
	if (out == NULL) out = PyObject_CallMethod(obj2, "__rdiv__", "O", obj1);
	if (out == NULL) {
		PY_TYPEERROR("unsupported operand type(s) for /: 'glm::detail::tmat3x4' and ", obj2);
		return NULL;
	}
	return out;
}

// inplace
// binaryfunc
static PyObject *
tmat3x4_iadd(tmat3x4 *self, PyObject *obj)
{
	tmat3x4 * temp = (tmat3x4*)tmat3x4_add((PyObject*)self, obj);

	if (temp == NULL) {
		return NULL;
	}

	self->x->x = temp->x->x;
	self->x->y = temp->x->y;
	self->x->z = temp->x->z;
	self->x->w = temp->x->w;
	self->y->x = temp->y->x;
	self->y->y = temp->y->y;
	self->y->z = temp->y->z;
	self->y->w = temp->y->w;
	self->z->x = temp->z->x;
	self->z->y = temp->z->y;
	self->z->z = temp->z->z;
	self->z->w = temp->z->w;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
tmat3x4_isub(tmat3x4 *self, PyObject *obj)
{
	tmat3x4 * temp = (tmat3x4*)tmat3x4_sub((PyObject*)self, obj);

	if (temp == NULL) {
		return NULL;
	}

	self->x->x = temp->x->x;
	self->x->y = temp->x->y;
	self->x->z = temp->x->z;
	self->x->w = temp->x->w;
	self->y->x = temp->y->x;
	self->y->y = temp->y->y;
	self->y->z = temp->y->z;
	self->y->w = temp->y->w;
	self->z->x = temp->z->x;
	self->z->y = temp->z->y;
	self->z->z = temp->z->z;
	self->z->w = temp->z->w;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
tmat3x4_imul(tmat3x4 *self, PyObject *obj)
{
	tmat3x4 * temp = (tmat3x4*)tmat3x4_mul((PyObject*)self, obj);

	if (temp == NULL) {
		return NULL;
	}

	if (!PyObject_TypeCheck(temp, &tmat3x4Type)) {
		PY_TYPEERROR("unsupported operand type for *=: ", obj);
		return NULL;
	}

	self->x->x = temp->x->x;
	self->x->y = temp->x->y;
	self->x->z = temp->x->z;
	self->x->w = temp->x->w;
	self->y->x = temp->y->x;
	self->y->y = temp->y->y;
	self->y->z = temp->y->z;
	self->y->w = temp->y->w;
	self->z->x = temp->z->x;
	self->z->y = temp->z->y;
	self->z->z = temp->z->z;
	self->z->w = temp->z->w;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
tmat3x4_idiv(tmat3x4 *self, PyObject *obj)
{
	tmat3x4 * temp = (tmat3x4*)tmat3x4_div((PyObject*)self, obj);

	if (temp == NULL) {
		return NULL;
	}

	if (!PyObject_TypeCheck(temp, &tmat3x4Type)) {
		PY_TYPEERROR("unsupported operand type for *=: ", obj);
		return NULL;
	}

	self->x->x = temp->x->x;
	self->x->y = temp->x->y;
	self->x->z = temp->x->z;
	self->x->w = temp->x->w;
	self->y->x = temp->y->x;
	self->y->y = temp->y->y;
	self->y->z = temp->y->z;
	self->y->w = temp->y->w;
	self->z->x = temp->z->x;
	self->z->y = temp->z->y;
	self->z->z = temp->z->z;
	self->z->w = temp->z->w;

	Py_DECREF(temp);
	Py_INCREF(self);
	return (PyObject*)self;
}

static PyObject *
tmat3x4_str(tmat3x4* self)
{
	char * out = (char*)malloc((190) * sizeof(char));
	snprintf(out, 190, "tmat3x4( ( %12.6g, %12.6g, %12.6g, %12.6g ), ( %12.6g, %12.6g, %12.6g, %12.6g ), ( %12.6g, %12.6g, %12.6g, %12.6g ) )", self->x->x, self->x->y, self->x->z, self->x->w, self->y->x, self->y->y, self->y->z, self->y->w, self->z->x, self->z->y, self->z->z, self->z->w);
	PyObject* po = PyUnicode_FromString(out);
	free(out);
	return po;
}

static PyObject *
tmat3x4_repr(tmat3x4* self)
{
	char * out = (char*)malloc((194) * sizeof(char));
	snprintf(out, 194, "tmat3x4\n[ %12.6g | %12.6g | %12.6g | %12.6g ]\n[ %12.6g | %12.6g | %12.6g | %12.6g ]\n[ %12.6g | %12.6g | %12.6g | %12.6g ]", self->x->x, self->x->y, self->x->z, self->x->w, self->y->x, self->y->y, self->y->z, self->y->w, self->z->x, self->z->y, self->z->z, self->z->w);
	PyObject* po = PyUnicode_FromString(out);
	free(out);
	return po;
}

static Py_ssize_t tmat3x4_len(tmat3x4 * self) {
	return (Py_ssize_t)3;
}

static PyObject* tmat3x4_sq_item(tmat3x4 * self, Py_ssize_t index) {
	switch (index) {
	case 0:
		Py_INCREF((PyObject*)self->x);
		return (PyObject*)self->x;
	case 1:
		Py_INCREF((PyObject*)self->y);
		return (PyObject*)self->y;
	case 2:
		Py_INCREF((PyObject*)self->z);
		return (PyObject*)self->z;
	case -1:
		Py_INCREF((PyObject*)self->z);
		return (PyObject*)self->z;
	case -2:
		Py_INCREF((PyObject*)self->y);
		return (PyObject*)self->y;
	case -3:
		Py_INCREF((PyObject*)self->x);
		return (PyObject*)self->x;
	default:
		PyErr_SetString(PyExc_IndexError, "index out of range");
		return NULL;
	}
}

static int tmat3x4_sq_setitem(tmat3x4 * self, Py_ssize_t index, PyObject * value) {
	ivec4*o = unpack_ivec4(value);
	if (o == NULL) {
		PY_TYPEERROR("expected tvec4, got ", value);
		return -1;
	}
	switch (index) {
	case 0:
		self->x->x = o->x;
		self->x->y = o->y;
		self->x->z = o->z;
		self->x->w = o->w;
		free(o);
		return 0;
	case 1:
		self->y->x = o->x;
		self->y->y = o->y;
		self->y->z = o->z;
		self->y->w = o->w;
		free(o);
		return 0;
	case 2:
		self->z->x = o->x;
		self->z->y = o->y;
		self->z->z = o->z;
		self->z->w = o->w;
		free(o);
		return 0;
	case -1:
		self->z->x = o->x;
		self->z->y = o->y;
		self->z->z = o->z;
		self->z->w = o->w;
		free(o);
		return 0;
	case -2:
		self->y->x = o->x;
		self->y->y = o->y;
		self->y->z = o->z;
		self->y->w = o->w;
		free(o);
		return 0;
	case -3:
		self->x->x = o->x;
		self->x->y = o->y;
		self->x->z = o->z;
		self->x->w = o->w;
		free(o);
		return 0;
	default:
		free(o);
		PyErr_SetString(PyExc_IndexError, "index out of range");
		return -1;
	}
}

static int tmat3x4_contains(tmat3x4 * self, PyObject * value) {
	if (IS_NUMERIC(value)) {
		double d = pyvalue_as_double(value);
		return (int)(d == self->x->x || d == self->x->y || d == self->x->z || d == self->x->w || d == self->y->x || d == self->y->y || d == self->y->z || d == self->y->w || d == self->z->x || d == self->z->y || d == self->z->z || d == self->z->w);
	}
	ivec4* o = unpack_ivec4(value);
	if (o == NULL) {
		return 0;
	}

	int out = (int)((self->x->x == o->x && self->x->y == o->y && self->x->z == o->z && self->x->w == o->w) || (self->y->x == o->x && self->y->y == o->y && self->y->z == o->z && self->y->w == o->w) || (self->z->x == o->x && self->z->y == o->y && self->z->z == o->z && self->z->w == o->w));
	free(o);
	return out;
}

static PyObject * tmat3x4_richcompare(tmat3x4 * self, PyObject * other, int comp_type) {
	tmat3x4 * other_as_tmat3x4;
	if (comp_type == Py_EQ) {
		if (!PyObject_TypeCheck(other, &tmat3x4Type)) { // incopatible type
			Py_RETURN_FALSE;
		}
		else {
			other_as_tmat3x4 = (tmat3x4*)other;
		}
		return PyBool_FromLong(
			(self->x->x == other_as_tmat3x4->x->x) && (self->x->y == other_as_tmat3x4->x->y) && (self->x->z == other_as_tmat3x4->x->z) && (self->x->w == other_as_tmat3x4->x->w) &&
			(self->y->x == other_as_tmat3x4->y->x) && (self->y->y == other_as_tmat3x4->y->y) && (self->y->z == other_as_tmat3x4->y->z) && (self->y->w == other_as_tmat3x4->y->w) &&
			(self->z->x == other_as_tmat3x4->z->x) && (self->z->y == other_as_tmat3x4->z->y) && (self->z->z == other_as_tmat3x4->z->z) && (self->z->w == other_as_tmat3x4->z->w));
	}
	else if (comp_type == Py_NE) {
		if (!PyObject_TypeCheck(other, &tmat3x4Type)) { // incopatible type
			Py_RETURN_TRUE;
		}
		else {
			other_as_tmat3x4 = (tmat3x4*)other;
		}
		return PyBool_FromLong(
			(self->x->x != other_as_tmat3x4->x->x) || (self->x->y != other_as_tmat3x4->x->y) || (self->x->z != other_as_tmat3x4->x->z) || (self->x->w != other_as_tmat3x4->x->w) ||
			(self->y->x != other_as_tmat3x4->y->x) || (self->y->y != other_as_tmat3x4->y->y) || (self->y->z != other_as_tmat3x4->y->z) || (self->y->w != other_as_tmat3x4->y->w) ||
			(self->z->x != other_as_tmat3x4->z->x) || (self->z->y != other_as_tmat3x4->z->y) || (self->z->z != other_as_tmat3x4->z->z) || (self->z->w != other_as_tmat3x4->z->w));
	}
	else {
		PY_TYPEERROR("unsupported operand type(s) for ==: 'glm::detail::tmat3x4 and ", other);
		return NULL;
	}
}

static int tmat3x4_setattr(PyObject * obj, PyObject * name, PyObject * value) {
	char * name_as_ccp;
#if PY3K
	name_as_ccp = PyBytes_AsString(PyUnicode_AsASCIIString(name));
#else
	name_as_ccp = PyString_AsString(PyUnicode_AsASCIIString(name));
#endif
	if ((strlen(name_as_ccp) >= 4 && name_as_ccp[0] == '_' && name_as_ccp[1] == '_' && name_as_ccp[strlen(name_as_ccp) - 1] == '_' && name_as_ccp[strlen(name_as_ccp) - 2] == '_')) {
		return PyObject_GenericSetAttr(obj, name, value);
	}
	if (strcmp(name_as_ccp, "x") == 0) {
		ivec4* o = unpack_ivec4(value);
		if (o == NULL) {
			PY_TYPEERROR("unsupported operand type for =: ", value);
			return -1;
		}
		((tmat3x4*)obj)->x->x = o->x;
		((tmat3x4*)obj)->x->y = o->y;
		((tmat3x4*)obj)->x->z = o->z;
		((tmat3x4*)obj)->x->w = o->w;
		free(o);
		return 0;
	}
	if (strcmp(name_as_ccp, "y") == 0) {
		ivec4* o = unpack_ivec4(value);
		if (o == NULL) {
			PY_TYPEERROR("unsupported operand type for =: ", value);
			return -1;
		}
		((tmat3x4*)obj)->y->x = o->x;
		((tmat3x4*)obj)->y->y = o->y;
		((tmat3x4*)obj)->y->z = o->z;
		((tmat3x4*)obj)->y->w = o->w;
		free(o);
		return 0;
	}
	if (strcmp(name_as_ccp, "z") == 0) {
		ivec4* o = unpack_ivec4(value);
		if (o == NULL) {
			PY_TYPEERROR("unsupported operand type for =: ", value);
			return -1;
		}
		((tmat3x4*)obj)->z->x = o->x;
		((tmat3x4*)obj)->z->y = o->y;
		((tmat3x4*)obj)->z->z = o->z;
		((tmat3x4*)obj)->z->w = o->w;
		free(o);
		return 0;
	}
	return PyObject_GenericSetAttr(obj, name, value);
}

// iterator

static PyObject *
tmat3x4Iter_new(PyTypeObject *type, PyObject *args, PyObject *kwargs)
{
	tmat3x4 *sequence;

	if (!PyArg_UnpackTuple(args, "__iter__", 1, 1, &sequence))
		return NULL;

	/* Create a new tmat3x4Iter and initialize its state - pointing to the last
	* index in the sequence.
	*/
	tmat3x4Iter *rgstate = (tmat3x4Iter *)type->tp_alloc(type, 0);
	if (!rgstate)
		return NULL;

	rgstate->sequence = sequence;
	rgstate->seq_index = 0;

	return (PyObject *)rgstate;
}

static void
tmat3x4Iter_dealloc(tmat3x4Iter *rgstate)
{
	Py_XDECREF(rgstate->sequence);
	Py_TYPE(rgstate)->tp_free(rgstate);
}

static PyObject *
tmat3x4Iter_next(tmat3x4Iter *rgstate)
{
	if (rgstate->seq_index < 3) {
		switch (rgstate->seq_index) {
		case 0:
			rgstate->seq_index++;
			Py_INCREF((PyObject*)(rgstate->sequence->x));
			return (PyObject*)(rgstate->sequence->x);
		case 1:
			rgstate->seq_index++;
			Py_INCREF((PyObject*)(rgstate->sequence->y));
			return (PyObject*)(rgstate->sequence->y);
		case 2:
			rgstate->seq_index++;
			Py_INCREF((PyObject*)(rgstate->sequence->z));
			return (PyObject*)(rgstate->sequence->z);
		}
	}
	rgstate->seq_index = 3;
	Py_CLEAR(rgstate->sequence);
	return NULL;
}

static PyObject * tmat3x4_geniter(tmat3x4 * self) {
	PyObject * obj = tmat3x4Iter_new(&tmat3x4IterType, Py_BuildValue("(O)", (PyObject *)self), Py_BuildValue("{}"));
	return obj;
}

static PySequenceMethods tmat3x4SeqMethods = {
	(lenfunc)tmat3x4_len, // sq_length
	0, // sq_concat
	0, // sq_repeat
	(ssizeargfunc)tmat3x4_sq_item, // sq_item
	0,
	(ssizeobjargproc)tmat3x4_sq_setitem, // sq_ass_item
	0,
	(objobjproc)tmat3x4_contains, // sq_contains
	0, // sq_inplace_concat
	0, // sq_inplace_repeat
};

static PyMemberDef tmat3x4_members[] = {
	{ "x", T_OBJECT, offsetof(tmat3x4, x), 0,
	"vec x" },
{ "y", T_OBJECT, offsetof(tmat3x4, y), 0,
"vec y" },
{ "z", T_OBJECT, offsetof(tmat3x4, z), 0,
"vec z" },
{ "col_type", T_OBJECT, offsetof(tmat3x4, col_type), 0,
"column type" },
{ "row_type", T_OBJECT, offsetof(tmat3x4, row_type), 0,
"row type" },
{ NULL }  /* Sentinel */
};

#if PY3K
static PyNumberMethods tmat3x4NumMethods = {
	(binaryfunc)tmat3x4_add,
	(binaryfunc)tmat3x4_sub,
	(binaryfunc)tmat3x4_mul,
	0, //nb_remainder
	0, //nb_divmod
	0, //nb_power
	(unaryfunc)tmat3x4_neg, //nb_negative
	(unaryfunc)tmat3x4_pos, //nb_positive
	(unaryfunc)tmat3x4_abs, //nb_absolute
	0, //nb_bool
	0, //nb_invert
	0, //nb_lshift
	0, //nb_rshift
	0, //nb_and
	0, //nb_xor
	0, //nb_or
	0, //nb_int
	0, //nb_reserved
	0, //nb_float

	(binaryfunc)tmat3x4_iadd, //nb_inplace_add
	(binaryfunc)tmat3x4_isub, //nb_inplace_subtract
	(binaryfunc)tmat3x4_imul, //nb_inplace_multiply
	0, //nb_inplace_remainder
	0, //nb_inplace_power
	0, //nb_inplace_lshift
	0, //nb_inplace_rshift
	0, //nb_inplace_and
	0, //nb_inplace_xor
	0, //nb_inplace_or

	0, //nb_floor_divide
	(binaryfunc)tmat3x4_div,
	0, //nb_inplace_floor_divide
	(binaryfunc)tmat3x4_idiv, //nb_inplace_true_divide

	0, //nb_index
};
#else
static PyNumberMethods tmat3x4NumMethods = {
	(binaryfunc)tmat3x4_add, //nb_add;
	(binaryfunc)tmat3x4_sub, //nb_subtract;
	(binaryfunc)tmat3x4_mul, //nb_multiply;
	(binaryfunc)tmat3x4_div, //nb_divide;
	0, //nb_remainder;
	0, //nb_divmod;
	0, //nb_power;
	(unaryfunc)tmat3x4_neg, //nb_negative;
	(unaryfunc)tmat3x4_pos, //nb_positive;
	(unaryfunc)tmat3x4_abs, //nb_absolute;
	0, //nb_nonzero;       /* Used by PyObject_IsTrue */
	0, //nb_invert;
	0, //nb_lshift;
	0, //nb_rshift;
	0, //nb_and;
	0, //nb_xor;
	0, //nb_or;
	0, //nb_coerce;       /* Used by the coerce() function */
	0, //nb_int;
	0, //nb_long;
	0, //nb_float;
	0, //nb_oct;
	0, //nb_hex;

	   /* Added in release 2.0 */
	   (binaryfunc)tmat3x4_iadd, //nb_inplace_add;
	   (binaryfunc)tmat3x4_isub, //nb_inplace_subtract;
	   (binaryfunc)tmat3x4_imul, //nb_inplace_multiply;
	   (binaryfunc)tmat3x4_idiv, //nb_inplace_divide;
	   0, //nb_inplace_remainder;
	   0, //nb_inplace_power;
	   0, //nb_inplace_lshift;
	   0, //nb_inplace_rshift;
	   0, //nb_inplace_and;
	   0, //nb_inplace_xor;
	   0, //nb_inplace_or;

		  /* Added in release 2.2 */
		  0, //nb_floor_divide;
		  (binaryfunc)tmat3x4_div, //nb_true_divide;
		  0, //nb_inplace_floor_divide;
		  (binaryfunc)tmat3x4_idiv, //nb_inplace_true_divide;
};
#endif

static PyTypeObject tmat3x4Type = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"glm::detail::tmat3x4",             /* tp_name */
	sizeof(tmat3x4),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)tmat3x4_dealloc, /* tp_dealloc */
	0,                         /* tp_print */
	0,                         /* tp_getattr */
	0,                         /* tp_setattr */
	0,                         /* tp_reserved */
	(reprfunc)tmat3x4_repr,                         /* tp_repr */
	&tmat3x4NumMethods,             /* tp_as_number */
	&tmat3x4SeqMethods,                         /* tp_as_sequence */
	0,                         /* tp_as_mapping */
	0,                         /* tp_hash  */
	0,                         /* tp_call */
	(reprfunc)tmat3x4_str,                         /* tp_str */
	0,//(getattrofunc)tmat3x4_getattr,                         /* tp_getattro */
	(setattrofunc)tmat3x4_setattr,                         /* tp_setattro */
	0,                         /* tp_as_buffer */
	Py_TPFLAGS_DEFAULT |
	Py_TPFLAGS_BASETYPE,   /* tp_flags */
	"tmat3x4( <tmat3x4 compatible type(s)> )\n3 columns of 3 components matrix of medium qualifier floating-point numbers.",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	(richcmpfunc)tmat3x4_richcompare,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	(getiterfunc)tmat3x4_geniter,                         /* tp_iter */
	0,                         /* tp_iternext */
	0,             /* tp_methods */
	tmat3x4_members,             /* tp_members */
	0,           			/* tp_getset */
	0,                         /* tp_base */
	0,                         /* tp_dict */
	0,                         /* tp_descr_get */
	0,                         /* tp_descr_set */
	0,                         /* tp_dictoffset */
	(initproc)tmat3x4_init,      /* tp_init */
	0,                         /* tp_alloc */
	(newfunc)tmat3x4_new,                 /* tp_new */
};

static PyTypeObject tmat3x4IterType = {
	PyVarObject_HEAD_INIT(NULL, 0)
	"tmat3x4Iter",             /* tp_name */
	sizeof(tmat3x4Iter),             /* tp_basicsize */
	0,                         /* tp_itemsize */
	(destructor)tmat3x4Iter_dealloc, /* tp_dealloc */
	0,                         /* tp_print */
	0,                         /* tp_getattr */
	0,                         /* tp_setattr */
	0,                         /* tp_reserved */
	0,                         /* tp_repr */
	0,             /* tp_as_number */
	0,                         /* tp_as_sequence */
	0,                         /* tp_as_mapping */
	0,                         /* tp_hash  */
	0,                         /* tp_call */
	0,                         /* tp_str */
	0,                         /* tp_getattro */
	0,                         /* tp_setattro */
	0,                         /* tp_as_buffer */
	Py_TPFLAGS_DEFAULT,   /* tp_flags */
	"tmat3x4 iterator",           /* tp_doc */
	0,                         /* tp_traverse */
	0,                         /* tp_clear */
	0,                         /* tp_richcompare */
	0,                         /* tp_weaklistoffset */
	0,                         /* tp_iter */
	(iternextfunc)tmat3x4Iter_next,                         /* tp_iternext */
	0,             /* tp_methods */
	0,             /* tp_members */
	0,           			/* tp_getset */
	0,                         /* tp_base */
	0,                         /* tp_dict */
	0,                         /* tp_descr_get */
	0,                         /* tp_descr_set */
	0,                         /* tp_dictoffset */
	0,      /* tp_init */
	0,                         /* tp_alloc */
	(newfunc)tmat3x4Iter_new,                 /* tp_new */
};