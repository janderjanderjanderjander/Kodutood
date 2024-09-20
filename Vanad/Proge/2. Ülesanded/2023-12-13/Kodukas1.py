def auto_hind(auto_hind_enne, aastate_arv):
    if aastate_arv == 0:
        return auto_hind_enne
    else:
        return auto_hind(round(auto_hind_enne * 0.8, 2), aastate_arv - 1)
