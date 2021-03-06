/*  =========================================================================
    zs_units_si - scaling atomics

    ** WARNING *************************************************************
    THIS SOURCE FILE IS 100% GENERATED. If you edit this file, you will lose
    your changes at the next build cycle. This is great for temporary printf
    statements. DO NOT MAKE ANY CHANGES YOU WISH TO KEEP. The correct places
    for commits are:

     * The XML model used for this code generation: zs_units_si.xml, or
     * The code generation script that built this file: zs_scaling
    ************************************************************************
    =========================================================================
*/

#ifndef ZS_UNITS_SI_H_INCLUDED
#define ZS_UNITS_SI_H_INCLUDED

#ifndef S_APPLY_SCALE_DEFINED
#define S_APPLY_SCALE_DEFINED
//  Applies a scale up to a pipe register
static void
s_scale_up (zs_pipe_t *input, zs_pipe_t *output, int64_t scale)
{
    if (zs_pipe_type (input) == 'w')
        zs_pipe_send_whole (output, zs_pipe_whole (input) * scale);
    else
    if (zs_pipe_type (input) == 'r')
        zs_pipe_send_real (output, zs_pipe_real (input) * (double) scale);
    else {
        //  String could be real or whole
        if ((double) zs_pipe_whole (input) == zs_pipe_real (input))
            zs_pipe_send_whole (output, zs_pipe_whole (input) * scale);
        else
            zs_pipe_send_real (output, zs_pipe_real (input) * scale);
    }
}
#endif

static int
s_Ki (zs_vm_t *self, zs_pipe_t *input, zs_pipe_t *output)
{
    if (zs_vm_probing (self)) {
        zs_vm_register (self, "Ki", zs_type_modest, "Scale by 2^10");
    }
    else {
        //  Process all values on input pipe
        while (zs_pipe_recv (input)) {
            s_scale_up (input, output, (int64_t) (1024LL));
        }
    }
    return 0;
}

static int
s_Mi (zs_vm_t *self, zs_pipe_t *input, zs_pipe_t *output)
{
    if (zs_vm_probing (self)) {
        zs_vm_register (self, "Mi", zs_type_modest, "Scale by 2^20");
    }
    else {
        //  Process all values on input pipe
        while (zs_pipe_recv (input)) {
            s_scale_up (input, output, (int64_t) (1024LL * 1024LL));
        }
    }
    return 0;
}

static int
s_Gi (zs_vm_t *self, zs_pipe_t *input, zs_pipe_t *output)
{
    if (zs_vm_probing (self)) {
        zs_vm_register (self, "Gi", zs_type_modest, "Scale by 2^30");
    }
    else {
        //  Process all values on input pipe
        while (zs_pipe_recv (input)) {
            s_scale_up (input, output, (int64_t) (1024LL * 1024LL * 1024LL));
        }
    }
    return 0;
}

static int
s_Ti (zs_vm_t *self, zs_pipe_t *input, zs_pipe_t *output)
{
    if (zs_vm_probing (self)) {
        zs_vm_register (self, "Ti", zs_type_modest, "Scale by 2^40");
    }
    else {
        //  Process all values on input pipe
        while (zs_pipe_recv (input)) {
            s_scale_up (input, output, (int64_t) (1024LL * 1024LL * 1024LL * 1024LL));
        }
    }
    return 0;
}

static int
s_Pi (zs_vm_t *self, zs_pipe_t *input, zs_pipe_t *output)
{
    if (zs_vm_probing (self)) {
        zs_vm_register (self, "Pi", zs_type_modest, "Scale by 2^50");
    }
    else {
        //  Process all values on input pipe
        while (zs_pipe_recv (input)) {
            s_scale_up (input, output, (int64_t) (1024LL * 1024LL * 1024LL * 1024LL * 1024LL));
        }
    }
    return 0;
}

static int
s_Ei (zs_vm_t *self, zs_pipe_t *input, zs_pipe_t *output)
{
    if (zs_vm_probing (self)) {
        zs_vm_register (self, "Ei", zs_type_modest, "Scale by 2^60");
    }
    else {
        //  Process all values on input pipe
        while (zs_pipe_recv (input)) {
            s_scale_up (input, output, (int64_t) (1024LL * 1024LL * 1024LL * 1024LL * 1024LL * 1024LL));
        }
    }
    return 0;
}

static int
s_da (zs_vm_t *self, zs_pipe_t *input, zs_pipe_t *output)
{
    if (zs_vm_probing (self)) {
        zs_vm_register (self, "da", zs_type_modest, "Scale by 10");
    }
    else {
        //  Process all values on input pipe
        while (zs_pipe_recv (input)) {
            s_scale_up (input, output, (int64_t) (10));
        }
    }
    return 0;
}

static int
s_h (zs_vm_t *self, zs_pipe_t *input, zs_pipe_t *output)
{
    if (zs_vm_probing (self)) {
        zs_vm_register (self, "h", zs_type_modest, "Scale by 100");
    }
    else {
        //  Process all values on input pipe
        while (zs_pipe_recv (input)) {
            s_scale_up (input, output, (int64_t) (100));
        }
    }
    return 0;
}

static int
s_k (zs_vm_t *self, zs_pipe_t *input, zs_pipe_t *output)
{
    if (zs_vm_probing (self)) {
        zs_vm_register (self, "k", zs_type_modest, "Scale by 1000");
    }
    else {
        //  Process all values on input pipe
        while (zs_pipe_recv (input)) {
            s_scale_up (input, output, (int64_t) (1000));
        }
    }
    return 0;
}

static int
s_M (zs_vm_t *self, zs_pipe_t *input, zs_pipe_t *output)
{
    if (zs_vm_probing (self)) {
        zs_vm_register (self, "M", zs_type_modest, "Scale by 10^6");
    }
    else {
        //  Process all values on input pipe
        while (zs_pipe_recv (input)) {
            s_scale_up (input, output, (int64_t) (1000000));
        }
    }
    return 0;
}

static int
s_G (zs_vm_t *self, zs_pipe_t *input, zs_pipe_t *output)
{
    if (zs_vm_probing (self)) {
        zs_vm_register (self, "G", zs_type_modest, "Scale by 10^9");
    }
    else {
        //  Process all values on input pipe
        while (zs_pipe_recv (input)) {
            s_scale_up (input, output, (int64_t) (1E9));
        }
    }
    return 0;
}

static int
s_T (zs_vm_t *self, zs_pipe_t *input, zs_pipe_t *output)
{
    if (zs_vm_probing (self)) {
        zs_vm_register (self, "T", zs_type_modest, "Scale by 10^12");
    }
    else {
        //  Process all values on input pipe
        while (zs_pipe_recv (input)) {
            s_scale_up (input, output, (int64_t) (1E12));
        }
    }
    return 0;
}

static int
s_P (zs_vm_t *self, zs_pipe_t *input, zs_pipe_t *output)
{
    if (zs_vm_probing (self)) {
        zs_vm_register (self, "P", zs_type_modest, "Scale by 10^15");
    }
    else {
        //  Process all values on input pipe
        while (zs_pipe_recv (input)) {
            s_scale_up (input, output, (int64_t) (1E15));
        }
    }
    return 0;
}

static int
s_E (zs_vm_t *self, zs_pipe_t *input, zs_pipe_t *output)
{
    if (zs_vm_probing (self)) {
        zs_vm_register (self, "E", zs_type_modest, "Scale by 10^18");
    }
    else {
        //  Process all values on input pipe
        while (zs_pipe_recv (input)) {
            s_scale_up (input, output, (int64_t) (1E18));
        }
    }
    return 0;
}

static int
s_Z (zs_vm_t *self, zs_pipe_t *input, zs_pipe_t *output)
{
    if (zs_vm_probing (self)) {
        zs_vm_register (self, "Z", zs_type_modest, "Scale by 10^21");
    }
    else {
        //  Process all values on input pipe
        while (zs_pipe_recv (input)) {
            //  Always coerce to a real value
            zs_pipe_send_real (output, zs_pipe_real (input) * (1E21));
        }
    }
    return 0;
}

static int
s_Y (zs_vm_t *self, zs_pipe_t *input, zs_pipe_t *output)
{
    if (zs_vm_probing (self)) {
        zs_vm_register (self, "Y", zs_type_modest, "Scale by 10^24");
    }
    else {
        //  Process all values on input pipe
        while (zs_pipe_recv (input)) {
            //  Always coerce to a real value
            zs_pipe_send_real (output, zs_pipe_real (input) * (1E24));
        }
    }
    return 0;
}

static int
s_d (zs_vm_t *self, zs_pipe_t *input, zs_pipe_t *output)
{
    if (zs_vm_probing (self)) {
        zs_vm_register (self, "d", zs_type_modest, "Scale by 1/10");
    }
    else {
        //  Process all values on input pipe
        while (zs_pipe_recv (input)) {
            //  Always coerce to a real value
            zs_pipe_send_real (output, zs_pipe_real (input) * (0.1));
        }
    }
    return 0;
}

static int
s_c (zs_vm_t *self, zs_pipe_t *input, zs_pipe_t *output)
{
    if (zs_vm_probing (self)) {
        zs_vm_register (self, "c", zs_type_modest, "Scale by 1/100");
    }
    else {
        //  Process all values on input pipe
        while (zs_pipe_recv (input)) {
            //  Always coerce to a real value
            zs_pipe_send_real (output, zs_pipe_real (input) * (0.01));
        }
    }
    return 0;
}

static int
s_m (zs_vm_t *self, zs_pipe_t *input, zs_pipe_t *output)
{
    if (zs_vm_probing (self)) {
        zs_vm_register (self, "m", zs_type_modest, "Scale by 1/1000");
    }
    else {
        //  Process all values on input pipe
        while (zs_pipe_recv (input)) {
            //  Always coerce to a real value
            zs_pipe_send_real (output, zs_pipe_real (input) * (1E-3));
        }
    }
    return 0;
}

static int
s_u (zs_vm_t *self, zs_pipe_t *input, zs_pipe_t *output)
{
    if (zs_vm_probing (self)) {
        zs_vm_register (self, "u", zs_type_modest, "Scale by 1/10^6");
    }
    else {
        //  Process all values on input pipe
        while (zs_pipe_recv (input)) {
            //  Always coerce to a real value
            zs_pipe_send_real (output, zs_pipe_real (input) * (1E-6));
        }
    }
    return 0;
}

static int
s_n (zs_vm_t *self, zs_pipe_t *input, zs_pipe_t *output)
{
    if (zs_vm_probing (self)) {
        zs_vm_register (self, "n", zs_type_modest, "Scale by 1/10^9");
    }
    else {
        //  Process all values on input pipe
        while (zs_pipe_recv (input)) {
            //  Always coerce to a real value
            zs_pipe_send_real (output, zs_pipe_real (input) * (1E-9));
        }
    }
    return 0;
}

static int
s_p (zs_vm_t *self, zs_pipe_t *input, zs_pipe_t *output)
{
    if (zs_vm_probing (self)) {
        zs_vm_register (self, "p", zs_type_modest, "Scale by 1/10^12");
    }
    else {
        //  Process all values on input pipe
        while (zs_pipe_recv (input)) {
            //  Always coerce to a real value
            zs_pipe_send_real (output, zs_pipe_real (input) * (1E-12));
        }
    }
    return 0;
}

static int
s_f (zs_vm_t *self, zs_pipe_t *input, zs_pipe_t *output)
{
    if (zs_vm_probing (self)) {
        zs_vm_register (self, "f", zs_type_modest, "Scale by 1/10^15");
    }
    else {
        //  Process all values on input pipe
        while (zs_pipe_recv (input)) {
            //  Always coerce to a real value
            zs_pipe_send_real (output, zs_pipe_real (input) * (1E-15));
        }
    }
    return 0;
}

static int
s_a (zs_vm_t *self, zs_pipe_t *input, zs_pipe_t *output)
{
    if (zs_vm_probing (self)) {
        zs_vm_register (self, "a", zs_type_modest, "Scale by 1/10^18");
    }
    else {
        //  Process all values on input pipe
        while (zs_pipe_recv (input)) {
            //  Always coerce to a real value
            zs_pipe_send_real (output, zs_pipe_real (input) * (1E-18));
        }
    }
    return 0;
}

static int
s_z (zs_vm_t *self, zs_pipe_t *input, zs_pipe_t *output)
{
    if (zs_vm_probing (self)) {
        zs_vm_register (self, "z", zs_type_modest, "Scale by 1/10^21");
    }
    else {
        //  Process all values on input pipe
        while (zs_pipe_recv (input)) {
            //  Always coerce to a real value
            zs_pipe_send_real (output, zs_pipe_real (input) * (1E-21));
        }
    }
    return 0;
}

static int
s_y (zs_vm_t *self, zs_pipe_t *input, zs_pipe_t *output)
{
    if (zs_vm_probing (self)) {
        zs_vm_register (self, "y", zs_type_modest, "Scale by 1/10^24");
    }
    else {
        //  Process all values on input pipe
        while (zs_pipe_recv (input)) {
            //  Always coerce to a real value
            zs_pipe_send_real (output, zs_pipe_real (input) * (1E-24));
        }
    }
    return 0;
}

static void
s_register_zs_units_si (zs_vm_t *self)
{
    zs_vm_probe (self, s_Ki);
    zs_vm_probe (self, s_Mi);
    zs_vm_probe (self, s_Gi);
    zs_vm_probe (self, s_Ti);
    zs_vm_probe (self, s_Pi);
    zs_vm_probe (self, s_Ei);
    zs_vm_probe (self, s_da);
    zs_vm_probe (self, s_h);
    zs_vm_probe (self, s_k);
    zs_vm_probe (self, s_M);
    zs_vm_probe (self, s_G);
    zs_vm_probe (self, s_T);
    zs_vm_probe (self, s_P);
    zs_vm_probe (self, s_E);
    zs_vm_probe (self, s_Z);
    zs_vm_probe (self, s_Y);
    zs_vm_probe (self, s_d);
    zs_vm_probe (self, s_c);
    zs_vm_probe (self, s_m);
    zs_vm_probe (self, s_u);
    zs_vm_probe (self, s_n);
    zs_vm_probe (self, s_p);
    zs_vm_probe (self, s_f);
    zs_vm_probe (self, s_a);
    zs_vm_probe (self, s_z);
    zs_vm_probe (self, s_y);
}
#endif
