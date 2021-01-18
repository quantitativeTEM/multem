function [atoms, lx, ly, lz, a, b, c, dz] = Ir001_xtl(na, nb, nc, ncu, rmsd_3d)
    if(nargin<5)
        rmsd_3d = 0.085;
    end
    
    % https://www.webelements.com/iridium/crystal_structure.html
    Z = ilm_Z('Ir');
    a = 3.8390;
    
    [atoms, lx, ly, lz, a, b, c, dz] = fcc001_xtl(Z, a, na, nb, nc, ncu, rmsd_3d);
end